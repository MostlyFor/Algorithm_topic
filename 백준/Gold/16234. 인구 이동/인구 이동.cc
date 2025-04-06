#include <iostream>
#include <queue>
using namespace std;

int n, L, R;
int board[50][50];
int dx[4] = {0,1, 0,-1};
int dy[4] = {1,0,-1,0};
int T; 


// 턴마다 초기화되는 정보
int visit[50][50];
vector<pair<int,int>> adj[50][50];
int total;

void init_turn(){
    total = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj[i][j].clear();
            visit[i][j] = 0;
        }
    }
}

void input(){
    cin >> n >> L >> R;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

bool in_range(int x,int y){
    return 0<=x && x<n && 0<=y && y<n;
}

void init_move(){ // 인구 차이 안나면 국경 모두 열기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int hx = i;
            int hy = j;
            for(int dir=0; dir<4; dir++){
                int nx = hx+dx[dir];
                int ny = hy+dy[dir];
                
                if(!in_range(nx,ny)) continue;
                
                if(L <= abs(board[nx][ny] - board[hx][hy]) && abs(board[nx][ny] - board[hx][hy]) <= R){
                    adj[hx][hy].push_back({nx,ny});
                    total++;
                }
            }
        }
    }
}

void bfs(int hx, int hy){
    vector<pair<int,int>> group;
    queue<pair<int,int>> q;
    q.push({hx,hy});
    visit[hx][hy] = 1;
    group.push_back({hx,hy});
    
    while(q.size()){
        auto h = q.front(); q.pop();
        int hx = h.first;
        int hy = h.second;
        
        for(auto tmp : adj[hx][hy]){
            int nx = tmp.first;
            int ny = tmp.second;
            
            if(visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            group.push_back({nx,ny});
            q.push({nx,ny});
        }
    }
    
    int population = 0;
    for(auto tmp : group){
        population += board[tmp.first][tmp.second];
    }
    
    for(auto tmp : group){
        board[tmp.first][tmp.second] = population / group.size();
    }
}

void move(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj[i][j].size() > 0 && visit[i][j] == 0){
                bfs(i, j);
            }
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
}

void test_init_move(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(auto tmp : adj[i][j]){
                cout << "연결" << i << ' ' << j << ' ' << tmp.first << ' ' << tmp.second << '\n';
            }
            cout << '\n';
        }
    }
}

int main(){
    input();
    
    while(1){
        init_turn();
        init_move();
        // test_init_move();
        if(total==0) break;
        T++;
        move();
    }
    
    // test_board();
    cout << T << '\n';
    return 0;
}