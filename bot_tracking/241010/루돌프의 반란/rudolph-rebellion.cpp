#include <iostream>
using namespace std;

// 1,1 시작
int N, M, P, C, D; // N 격자크기, M : 턴 수, P :산타 수 , C 루돌프 힘, D 산타 힘
int turn;

int rx, ry; // 루돌프 위치
int board[50][50]; // 산타 번호

pair<int,int> santa[31]; // 산타 번호와 위치
int santa_score[31]; // 산타 점수
int santa_stun[31];

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

void input(){
    cin >> N >> M >> P >> C >> D;
    cin >> rx >> ry;
    rx--; ry--;

    for(int i=0; i<P; i++){
        int id, x, y; cin >> id >> x >> y;
        x--; y--;
        
        board[x][y] = id;
        santa[id] ={x,y};
    }
}

void test_board(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool is_out(int x, int y){
    return x < 0 || y < 0 || x >= N || y >= N;
}

// x, y 앞으로 떨어질 지점, vx, vy는 밀려나는 방향
void interaction(int x, int y, int vx, int vy, int santa_idx){
    // 앞으로 떨어질 지점이 장외라면 그냥 종료
    if(is_out(x,y)){
        santa[santa_idx].first = -1;
        santa[santa_idx].second = -1;
        return;
    }
    // 빈 칸이라면 착지 후 종료
    if(board[x][y]==0){
        board[x][y] = santa_idx;
        santa[santa_idx].first = x;
        santa[santa_idx].second = y;
        return;
    }

    // 다른 산타가 있다면 
    int new_santa_idx = board[x][y];
    board[x][y] = santa_idx;
    santa[santa_idx].first = x;
    santa[santa_idx].second = y;
    interaction(x+vx, y+vy, vx, vy, new_santa_idx);
}


// 1. 루돌프 움직임
void ru_move(){
    int min_dist = 1e9;
    int min_idx = -1;
    int sx = -1;
    int sy = -1;

    // 1-1 가장 가까운 산타 (r > c >)
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>=0; j--){
            if(board[i][j] != 0){
                int dist = (i-rx)*(i-rx) + (j-ry)*(j-ry);
                if(min_dist > dist){
                    min_dist = dist;
                    min_idx = board[i][j];
                    sx = i;
                    sy = j;
                }
            }
        }
    }



    // 1-2 가장 가까운 산타와 가까워 지는 방향으로 이동
    min_dist = 1e9;
    int new_x = -1;
    int new_y = -1;

    for(int dir =0; dir<8; dir++){
        int nrx= rx+dx[dir];
        int nry= ry+dy[dir];

        if(is_out(nrx, nry)) continue;
        int dist = (nrx-sx)*(nrx-sx) + (nry-sy)*(nry-sy); // 산타와의 거리
        if(min_dist > dist){
            min_dist = dist;
            new_x = nrx;
            new_y = nry;
        }
    }
        
    int vx = new_x - rx;
    int vy = new_y - ry;

    rx = new_x;
    ry = new_y;

    // 루돌프 움직임 산타 충돌
    if(board[rx][ry]){
        int santa_idx = board[rx][ry];
        int santa_x = santa[santa_idx].first;
        int santa_y = santa[santa_idx].second;

        // cout << "충동 오류" << santa_x << ' ' << santa_y << '\n';
        

        board[santa_x][santa_y]= 0;
        santa_score[santa_idx] += C;
        santa_stun[santa_idx] = turn+1;
        
        interaction(santa_x + C * vx, santa_y + C * vy, vx, vy, santa_idx);
    }
}

void test_santa(){
    for(int i=0; i<=P; i++){
        cout << i << ' ' << santa[i].first << ' ' << santa[i].second << '\n';
    }
}



// 2. 산타 움직임
void sa_move(){
    
    for(int i=1; i<=P; i++){
        int sx = santa[i].first;
        int sy = santa[i].second;
        // cout << sx << ' ' << sy << '\n'; 

        // 산타 기절했는지 확인
        if(santa[i].first == -1 && santa[i].second == -1) continue;
        if(!(santa_stun[i] < turn)) continue;

        int min_dist = (sx-rx)*(sx-rx) + (sy-ry)*(sy-ry);
        int new_x = -1;
        int new_y = -1;

        for(int dir=0; dir<8; dir++){
            if(dx[dir] * dy[dir] != 0) continue; // 네 방향으로만 이동

            int nsx= sx+dx[dir];
            int nsy= sy+dy[dir];


            if(is_out(nsx, nsy)) continue; // 게임판 밖
            if(board[nsx][nsy]) continue; // 다른 산타 존재

            int dist = (nsx-rx)*(nsx-rx) + (nsy-ry)*(nsy-ry); // 산타와의 거리
            

            // cout << sx << "->" << nsx << ' ' << sy << "->" << nsy << ' ' << dist << '\n';

            if(min_dist > dist){
                min_dist = dist;
                new_x = nsx;
                new_y = nsy;
            }
        }
        
        // cout << i << "번째 산타 움직임" << new_x << ' ' << new_y << '\n';
        // 움직일 수 없다면 산타 움직이지 않음
        if(new_x == -1 && new_y == -1) continue;


        //산타와 루돌프 충돌
        if(new_x == rx && new_y == ry){

            santa_stun[i] = turn+1;

            santa_score[i] += D;
            int vx = - (new_x - sx);
            int vy = - (new_y - sy);

            new_x = new_x + D * vx;
            new_y = new_y + D * vy;


            // 다른 산타와 충돌 - 상호작용
            board[sx][sy] = 0;
            interaction(new_x, new_y, vx, vy, i);
        }

        // 산타와 루돌프 충돌 x
        else{
            board[sx][sy] = 0;
            board[new_x][new_y] = i;
            santa[i].first = new_x;
            santa[i].second = new_y;
        }
    }
}


int main(){

    input(); // 체크
    // test_board();
    // test_santa();

    while(turn < M){
        turn++;

        // cout << turn << "번째 움직임 관찰" << '\n';

        // 1. 루돌프 움직임 - 체크 
        ru_move();
        // test_board();
        // cout << rx << ' ' << ry << '\n';

        // 2. 산타 움직임 - 체크
        sa_move();
        // test_board();
        // cout << rx << ' ' << ry << '\n';

        // 3. 턴 종료 후 살아남은 모든 산타에게 1점 부여
        int cnt = 0;
        for(int i=1; i<=P; i++){
            if(santa[i].first == -1 && santa[i].second == -1) continue;
            santa_score[i]++;
            cnt++;
        }



        if(cnt == 0) break;
    }

    for(int i=1; i<=P; i++){
            cout << santa_score[i] << ' ';
     } cout << '\n';


    return 0;
}