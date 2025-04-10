#include <iostream>
#include <vector>
using namespace std;

int n, m, k; // n 격자, m 상어 수 , k 냄새 지속
int turn;

struct Shark{
    int x;
    int y;
    int d; // 현재 방향
    bool is_dead;
    
    int pr[4][4];
};

Shark sharks[401];

int board[20][20][3]; // 보드 :  현재 상어, 냄새 주인, 냄새 지속시간

void input(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j][0];
            if(board[i][j][0] != 0){
                int idx = board[i][j][0];
                sharks[idx].x = i;
                sharks[idx].y = j;
                sharks[idx].is_dead = false;
            }
        }
    }
    
    for(int idx=1; idx<=m; idx++){
        int dir; cin >> dir;
        dir--;
        sharks[idx].d = dir;
    }
    
    for(int idx=1; idx<=m; idx++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin >> sharks[idx].pr[i][j];
                sharks[idx].pr[i][j]--;
            }
        }
    }
}


bool is_end(){
    int cnt = 0;
    for(int idx=1; idx<=m; idx++){
        if(sharks[idx].is_dead == false) cnt++;
    }
    return cnt == 1;
}


// 현재 위치에 냄새 뿌림
void smell(){
    
    //  이전 냄새 1씩 감소
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j][2]) board[i][j][2]--;
        }
    }
    
    // 현재 상어 위치에서 냄새
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j][0] != 0){
                int idx = board[i][j][0];
                board[i][j][1] = idx;
                board[i][j][2] = k;
            }
        }
    }
}

bool in_range(int x,int y){
    return 0<=x && 0<=y && x <n && y < n;
}



void move(){
    // tmp_board를 보고 board 갱신
    int tmp_board[20][20];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp_board[i][j] = 0;
        }
    }
    
    int dx[4] = {-1,1,0,0}; // 위 아래 왼쪽 오른쪽
    int dy[4] = {0,0,-1,1};
    
    // 번호 큰 상어 순서대로 이동
    for(int idx = m; idx>=1; idx--){
        if(sharks[idx].is_dead) continue;
        
        int& hx = sharks[idx].x;
        int& hy = sharks[idx].y;
        int& d = sharks[idx].d;
        
        bool is_moved = false;
        
        // 1. 인접한 칸 중 아무 냄새가 없는 칸
        for(int dir_idx =0; dir_idx<4; dir_idx++){
            int dir = sharks[idx].pr[d][dir_idx]; // sharks[idx].pr[d] : 현재 보고 있는 방향의 우선순위
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];
            
            if(!in_range(nx, ny)) continue;
            if(board[nx][ny][2]) continue; // 냄새 있으면 안 감
            
            tmp_board[nx][ny] = idx;
            
            hx = nx;
            hy = ny;
            d = dir;
            is_moved = true;
            break;
        }
        
        // 2. 내 냄새가 있는 칸 
        if(is_moved) continue;
        for(int dir_idx =0; dir_idx<4; dir_idx++){
            int dir = sharks[idx].pr[d][dir_idx]; // sharks[idx].pr[d] : 현재 보고 있는 방향의 우선순위
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];
            
            if(!in_range(nx, ny)) continue;
            if(board[nx][ny][1] != idx && board[nx][ny][2] > 0) continue; // 다른 상어 냄새
            
            hx = nx;
            hy = ny;
            d = dir;
            
            tmp_board[nx][ny] = idx;
            break;
        }
    }
    
    
    // 상어 이동 후 상어 상태 목숨초기화, board 상태 초기화
    vector<int> arr; // 현재 살아있는 상어 목록 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tmp_board[i][j]){
                int idx = tmp_board[i][j];
                arr.push_back(idx);
            }
        }
    }
    
    for(int idx=1; idx<=m; idx++){
        sharks[idx].is_dead = true;
    }
    
    for(auto idx : arr){
        sharks[idx].is_dead = false;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j][0] = tmp_board[i][j];
        }
    }
    
    
}

void test_board(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j][0];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    input();
    smell();
    // test_board();
    while(1){
        turn++;
        if(turn == 1001) break;
        
        // 이전 냄새가 보존된 상태에서 이동
        // 이때 상어 동시에 이동 근데 번호 적은게 큰 것 덮는거니까 그냥 새로 하면 될 듯 
        move();
        
        // 이전 냄새 지우고 현재 냄새 ++
        smell();
        
        // test_board();
        
        // 상어 1 마리인지 확인
        if(is_end()) break;
    }
    
    if(turn == 1001) cout << -1 << '\n';
    else cout << turn;
    
    return 0;
}