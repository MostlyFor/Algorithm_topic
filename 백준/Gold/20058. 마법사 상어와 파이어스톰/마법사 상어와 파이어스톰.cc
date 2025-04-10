#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, q;
int board[1 << 6 + 1][1 << 6 + 1];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void input(){
    cin >> n >> q;
    n = 1 << n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

bool in_range(int x, int y){
    return 0<= x && 0<=y && x < n && y <n;
}
// 행렬 회전
void f(int x, int y, int L){
    vector<vector<int>> tmp(L, vector<int>(L, 0));
    
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            tmp[j][L-1-i] = board[x+i][y+j];
        }
    }
    
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            board[x+i][y+j] = tmp[i][j];
        }
    }
}

void test_board(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


void g(){
    int new_board[1 << 6 + 1][1 << 6 + 1]; // 3개 이하로 인접해있으면 1
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(board[i][j] == 0) {
                new_board[i][j] = 0;
                continue;
            }
            
            int adj = 0; // 인접해있는 개수 
            for(int dir=0; dir<4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(!in_range(nx,ny)) continue;
                if(board[nx][ny] > 0) adj++;
                
            }
            
            if(adj < 3) new_board[i][j] = 1;
            else new_board[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] -= new_board[i][j];
        }
    }
}

void output(){
    int ans = 0;
    int visit[65][65];
    
    // 1. 남아있는 얼음의 합
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += board[i][j];
            visit[i][j] = 0;
        }
    }
    
    
    int idx = 1;
    int ans2 = 0;
    
    
    // 얼음 덩어리 중 가장 큰 덩어리
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j]) continue; // 확인한 덩어리
            if(board[i][j] == 0) continue;
            
            queue<pair<int,int>> q;
            q.push({i, j});
            visit[i][j] = 1;
            int adj = 1; // 현재 만날 수 있는 얼음 수
            
            while(q.size()){
                auto h = q.front(); q.pop();
                int hx = h.first;
                int hy = h.second;
                
                for(int dir=0; dir<4; dir++){
                    int nx = hx + dx[dir];
                    int ny = hy + dy[dir];
                    
                    if(!in_range(nx,ny)) continue;
                    if(visit[nx][ny]) continue;
                    if(board[nx][ny] == 0) continue;
                    adj++;
                    visit[nx][ny] = visit[hx][hy] + 1;
                    q.push({nx,ny});
                }
            }
            
            ans2 =max(ans2, adj);
        }
    }
    
    cout << ans << '\n';
    cout << ans2 << '\n';
    
}

int main(){
    input();
    while(q--){
        int l; cin >> l;
        l = 1 << l;
        
        // 회전
        for(int i=0; i<n; i = i + l){
            for(int j=0; j<n; j = j + l){
                f(i, j, l);
            }
        }
        // cout << "녹기 전 :" << '\n';
        // test_board();
        // 얼음 녹음
        g();
        // cout << "녹기 후 :" << '\n';
        // test_board();
    }
    
    output();

    return 0;
}