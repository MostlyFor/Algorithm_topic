#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m;
int turn;
int board[20][20];
int score_board[20][20];
int visited[20][20];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int dice_x, dice_y, dice_dir;
int dice_number; // 땅에 닿는 숫자

map<pair<int,int>, int> dice_dict;


void bfs(){
    queue<pair<int,int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 1) continue;
            
            vector<pair<int,int>> now;
            queue<pair<int,int>> q;
            int score = board[i][j];
            q.push({i,j});
            now.push_back({i,j});
            visited[i][j] =1;
            while(q.size()){
                auto h = q.front(); q.pop();
                int hx= h.first;
                int hy = h.second;

                for(int dir=0; dir<4; dir++){
                    int nx = hx + dx[dir];
                    int ny = hy + dy[dir];

                    if(0 > nx || 0 > ny || n <= nx || n <= ny) continue;
                    if(visited[nx][ny]) continue;
                    if(board[hx][hy] != board[nx][ny]) continue;
                    score += board[nx][ny];
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                    now.push_back({nx,ny});
                }
            }

            for(auto tmp : now){
                score_board[tmp.first][tmp.second] = score;
            }
        }
    }

}

// 주사위 구현이 어려움
void test_score_board(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << score_board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void init(){
    dice_dict.insert({{6,0},3});
    dice_dict.insert({{6,1},2});
    dice_dict.insert({{6,2},4});
    dice_dict.insert({{6,3},5});
    
    dice_dict.insert({{4,0},6});
    dice_dict.insert({{4,1},2});
    dice_dict.insert({{4,2},1});
    dice_dict.insert({{4,3},5});
    
    dice_dict.insert({{1,0},4});
    dice_dict.insert({{1,1},2});
    dice_dict.insert({{1,2},3});
    dice_dict.insert({{1,3},5});
    
    dice_dict.insert({{3,0},1});
    dice_dict.insert({{3,1},2});
    dice_dict.insert({{3,2},6});
    dice_dict.insert({{3,3},5});
    
    dice_dict.insert({{2,0},3});
    dice_dict.insert({{2,1},1});
    dice_dict.insert({{2,2},4});
    dice_dict.insert({{2,3},6});
    
    dice_dict.insert({{5,0},3});
    dice_dict.insert({{5,1},6});
    dice_dict.insert({{5,2},4});
    dice_dict.insert({{5,3},1});

}

int main() {
    cin >> n >> m;
    int answer = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    // 0. 초기 점수 세팅
    bfs();
    // test_score_board();

    init();
    
    while(turn < m){
        turn++;

        if(turn == 1) dice_dir = dice_dir;
        // 주사위가 해당 숫자보다 클 경우 - 시계방향 이동
        else{
            if(dice_number > board[dice_x][dice_y]) dice_dir = (dice_dir+1) %4 ;
            else if(dice_number <  board[dice_x][dice_y]) dice_dir = (dice_dir+3) %4 ;
            else if(dice_number == board[dice_x][dice_y]) dice_dir = dice_dir;
        }

        int dice_nx = dice_x + dx[dice_dir];
        int dice_ny = dice_y + dy[dice_dir];
        if(dice_nx < 0 || dice_ny < 0 || dice_nx >= n || dice_ny >= n){
            dice_dir = (dice_dir+2)%4;
            dice_nx = dice_x + dx[dice_dir];
            dice_ny = dice_y + dy[dice_dir];
        }
        
        // 이동하는 곳 점수 합산
        answer += score_board[dice_nx][dice_ny];
        dice_x = dice_nx;
        dice_y = dice_ny;
        // dice_number 초기화
        dice_number = dice_dict[{dice_number, dice_dir}];
    }

    cout << answer;
    
    return 0;
}