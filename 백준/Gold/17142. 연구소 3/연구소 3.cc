#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int board[50][50]; // 0 : 빈칸, 1: 벽 ,2: 바이러스
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int>> virus;
int ans = 1e9;

bool in_range(int x, int y){
    return 0<=x && 0<= y && x < n && y < n;
}

void test_sboard(int sboard[][50]){
    cout << "sboard 배열 관찰" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << sboard[i][j] << ' ';
        }
        cout << '\n';
    }
}


void test_visit(int visit[][50]){
    cout << "visit 배열 관찰" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
}

void input(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j]; // 모든 칸 바이러스 걸리는데 드는 시간
            if(board[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }
}

int simulate(vector<int>& activate){ // 바이러스가 주어졌을 때 시뮬레이션
    int sboard[50][50];
    int visit[50][50];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sboard[i][j] = board[i][j];
            visit[i][j] = 0;
        }
    }
    
    for(auto v : virus){
        sboard[v.first][v.second] = -1;
    }
    
    queue<pair<int,int>> q;
    
    for(int i=0; i<activate.size(); i++){
        pair<int,int> v = virus[activate[i]];
        sboard[v.first][v.second] = 2;
        q.push(v);
        visit[v.first][v.second] = 1;
    }
    
    while(q.size()){
        auto h = q.front(); q.pop();
        int hx = h.first;
        int hy = h.second;
        
        for(int dir = 0; dir<4; dir++){
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];
            
            if(!in_range(nx,ny)) continue; // 범위 나간 경우
            if(sboard[nx][ny] == 1) continue; // 벽이 있는 경우
            if(visit[nx][ny]) continue; // 이미 방문한 경우
            
            
            visit[nx][ny] = visit[hx][hy] + 1;
            q.push({nx,ny});
        }
    }
    
    // 모든 칸에 바이러스 옮길 수 없는 경우
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(sboard[i][j] == 0 && visit[i][j] == 0) {
                return -1;
            }
        }
    }
    
    int res = -1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(sboard[i][j] == -1) continue;
            res = max(res, visit[i][j]);
        }
    }
    
    // // 0, 3, 4
    // if(activate[0] == 0 && activate[1] == 3 && activate[2] == 4){
    //     test_sboard(sboard);
    //     test_visit(visit);
    // }
    
    return res-1;
}

void solve(int idx, vector<int>& activate){
    if(activate.size() == m){
        int res = simulate(activate);
        if(res == -1) return;
        ans = min(ans, simulate(activate));
        return;
    }
    
    // for(int i = idx; i<m; i++){
    for(int i = idx; i<virus.size(); i++){
        activate.push_back(i);
        solve(i+1, activate);
        activate.pop_back();
    }
}

int main(){
    input();
    vector<int> activate;
    solve(0, activate);
    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}