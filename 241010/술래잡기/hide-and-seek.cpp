#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m, h, k; // m 도망자 수, h - 나무의 수, k 턴
int turn;
int answer;

int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서 
int dy[4] = {0, 1, 0, -1};


int sul; //술래 처음 위치
int sul_mode = -1; // 1씩 줄어드는 단계


int tree[100][100]; // 나무의 위치
int board[100][100]; // 술래 위치
int board2[100][100]; // 술래 위치 test
int runner2[100][100]; // 러너 위치 test


unordered_map<int,pair<int,int>> sul_map;


vector<pair<int,int>> runner[10000]; // runner[번호] = {위치}
int runner_dir[10000]; // runner 방향


void input(){
    cin >> n >> m >> h >> k;

    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        runner[i].push_back({a-1,b-1});

        cin >> a;
        if(a == 1) runner_dir[i] = 1;
        else if(a == 2) runner_dir[i] = 2;
    }
    
    // 나무 위치 받기
    for(int i=0; i<h; i++){
        int a,b; cin >> a >> b;
        tree[a-1][b-1] = 1;
    }

}

// 2. 술래 이동
void sul_move(){
    int sul_x = sul_map[sul].first;
    int sul_y = sul_map[sul].second;

    board2[sul_x][sul_y] = 0;

    if(sul_mode == -1) sul--;
    else if(sul_mode = 1) sul++;

    int sul_nx = sul_map[sul].first;
    int sul_ny = sul_map[sul].second;

    board2[sul_x][sul_y] = turn;

    if(sul == 25 || sul == 1) sul_mode *= -1;
}

// 1. m명의 도망자 이동
void runner_move(){
    //1-1. 거리가 3 이하인 도망자 이동
    for(int i=0; i<m; i++){
        int x = runner[i][0].first;
        int y=  runner[i][0].second;
        int sul_x = sul_map[sul].first;
        int sul_y = sul_map[sul].second;

        int dist = abs(x-sul_x) + abs(y-sul_y);
        if(dist >3) continue; // 거리가 3 이상인 도망자 pass

        int nx = x + dx[runner_dir[i]];
        int ny = y + dy[runner_dir[i]];


        if(0 > nx || 0 > ny || nx >= n || ny >= n){
            runner_dir[i] = (runner_dir[i] + 2) % 4;
            nx = x + dx[runner_dir[i]];
            ny = y + dy[runner_dir[i]];      
        }

        // 움직이는 칸에 술래가 있는 경우
        if((nx == sul_x) && (ny == sul_y)) continue;

        // 술래가 없다면 이동
        runner[i][0].first = nx;
        runner[i][0].second = ny;
    }
}

void check_board(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// 술래 이동 방향 초기화
void init_sul_map(){
    int cnt = 1;
    int cnt_dir = 2;
    int i = 0;
    int j = 0;

    while(cnt <= n * n){
        board[i][j] = cnt;
        cnt++;
        int ni = i + dx[cnt_dir];
        int nj = j + dy[cnt_dir];

        // 범위 바깥으로 나가거나 값이 차있는 경우
        if(0 > ni || 0 > nj || n <= ni || n<=nj || board[ni][nj] != 0){
            cnt_dir = (cnt_dir+3)%4;
            ni = i + dx[cnt_dir];
            nj = j + dy[cnt_dir];
        }

        i = ni;
        j = nj;
    }

    // check_board();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sul_map[board[i][j]] = {i,j};
        }
    }
}

void test_runner(){
    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            runner2[j][k] = 0;
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0; i<m; i++){
        int x = runner[i][0].first;
        int y =  runner[i][0].second;
        runner2[x][y] = i+1;
    }

    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            cout << runner2[j][k] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


int catch_runner(){
    int catcher = 0;


    int tmp_sul = sul;

    int sul_x = sul_map[tmp_sul].first;
    int sul_y = sul_map[tmp_sul].second;
    

    if(sul_mode == -1) tmp_sul--;
    else if(sul_mode = 1) tmp_sul++;

    int sul_nx = sul_map[tmp_sul].first;
    int sul_ny = sul_map[tmp_sul].second;

    
    int sul_xdir = sul_nx - sul_x; 
    int sul_ydir = sul_ny - sul_y;

    int sul_nnx = sul_nx + sul_xdir;
    int sul_nny = sul_ny + sul_ydir;

    // 술래의 시야 3칸
    for(int i=0; i<m; i++){
        int x = runner[i][0].first;
        int y=  runner[i][0].second;

        if((x == sul_x && y == sul_y) || (x == sul_nx && y == sul_ny) || (x == sul_nnx && y == sul_nny)){
            if(tree[x][y] == 0){
                runner[i][0].first = -1e9;
                runner[i][0].second = -1e9;
                catcher++;
            }
        }
    }
    


    return catcher;
}
int main() {
    input();

    init_sul_map();
    sul = n*n;

    // test_runner();

    while(turn < k){
        // 0. 초기화
        turn++;

        // 1. 도망자 이동
        runner_move();

        // test_runner();

        // 2. 술래 이동
        sul_move();

        // if(16 < turn)
        //     check_board();

        // 3. 술래 시야에 있는 도망자 잡기
        int catcherr = catch_runner();


        // turn * 현재 턴에서 잡힌 도망자의 수
        answer += turn * catcherr;

    }

    cout << answer;

    return 0;
}