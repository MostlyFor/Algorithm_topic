#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int board[11][11];
int ans = 0;
int n, k, u, d;

vector<vector<int>> citys;

void select(vector<int> arr, int idx){
    if(arr.size() == k){
        citys.push_back(arr);
        return;
    }

    for(int i=idx; i<n * n; i++){
        arr.push_back(i);
        select(arr, i+1);
        arr.pop_back();
    }
}
bool InRange(int x, int y){
    return 0<=x && 0<=y && x<n && y<n;
}
void bfs(vector<int> city){
    int tmp =0;
    int visit[11][11] = {};
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    queue<pair<int,int>> q;
    for(auto ct : city){
        q.push({ct/n, ct%n});
        visit[ct/n][ct%n] =1;
        tmp++;
    }

    while(q.size()){
        auto h = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = h.first + dx[i];
            int ny = h.second + dy[i];
            int high = board[h.first][h.second];
            if(!InRange(nx,ny)) continue;
            if(visit[nx][ny]) continue;
            if(abs(high - board[nx][ny]) <= d && abs(high - board[nx][ny] >=u)){
                tmp++;
                visit[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }

    ans = max(ans, tmp);
}

int main() {
    cin >> n >> k >> u >> d;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    select(vector<int>(), 0);    // 1. 도시 k개 고르기     // 64 C 3


    // 2. 해당 도시로부터 bfs로 방문 가능한 도시 수 세기
    for(auto city : citys){
        bfs(city);
    }

    cout << ans;
    
    return 0;
}