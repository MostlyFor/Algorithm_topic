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
int dice_front, dice_side, dice_up;

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
    dice_front = 2;
    dice_up = 1;
    dice_side = 3;

    init();
    
    while(turn < m){
        turn++;

        // cout << turn << "번째 관찰 - 이동 전, " << '(' << dice_x << ',' << dice_y << ')' << ' ' <<dice_dir << ' ' << dice_number << '\n';
        if(turn == 1) dice_dir = dice_dir;
        // 주사위가 해당 숫자보다 클 경우 - 시계방향 이동
        else{
            if(7-dice_up > board[dice_x][dice_y]) dice_dir = (dice_dir+1) %4 ;
            else if(7-dice_up <  board[dice_x][dice_y]) dice_dir = (dice_dir+3) %4 ;
            else if(7-dice_up == board[dice_x][dice_y]) dice_dir = dice_dir;
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
        // dice 상태 초기화
        if(dice_dir == 0) {int tmp = dice_side; dice_side = dice_up; dice_up = 7-tmp;}
        if(dice_dir == 1) {int tmp = dice_front; dice_front = dice_up; dice_up = 7-tmp;}
        if(dice_dir == 2) {int tmp = dice_side; dice_side = 7-dice_up; dice_up = tmp;}
        if(dice_dir == 3) {int tmp = dice_front; dice_front = 7-dice_up; dice_up = tmp;}

        // cout << turn << "번째 관찰 - 이동 후, " << '(' << dice_x << ',' << dice_y << ')' << ' ' << dice_dir << ' ' << dice_number << '\n';
    }

    cout << answer;
    
    return 0;
}