#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
int board[20][20]; // 검은색 블록(-1) , 무지개 블록 (0) , 일반 블록 (M가지 색상), 빈칸 (-2)
int score;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


// 그룹 - 1. 일반 블록 적어도 하나, 일반 블록은 색은 모두 같음, 검은색 블록 x 무지개 블록 있어도 됨
// 그룹은 크기 2 이상

// 왼쪽위가 기준 블록


void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}


void rotate(){
    int tmp[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[n-1-j][i] = board[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void gravity(){
    for(int j=0; j<n; j++){
        int idx = -1; // 이전에 만난 경계의 높이 
        
        for(int i=0; i<=n; i++){
            
            // 경계를 만난 경우
            if(i == n){
                vector<int> arr; // 
                for(int k=idx+1; k<i; k++){
                    if(board[k][j] >=0) arr.push_back(board[k][j]);
                    board[k][j] = -2;
                }
                
                for(int k=arr.size()-1; k>=0; k--){
                    int kk = arr.size() - k;
                    // cout << idx << ' ' << i << ' ' << j << ' ' << k << '\n';
                    board[i-kk][j] = arr[k];
                }
                
                break;
            }
            
            // 블록을 만난 경우
            if(board[i][j] == -1){
                vector<int> arr; // 
                for(int k=idx+1; k<i; k++){
                    if(board[k][j] >=0) arr.push_back(board[k][j]);
                    board[k][j] = -2;
                }
                
                for(int k=arr.size()-1; k>=0; k--){
                    int kk = arr.size() - k;
                    // cout << idx << ' ' << i << ' ' << j << ' ' << k << '\n';
                    board[i-kk][j] = arr[k];
                }
                
                idx = i;
            }
        }
    }
}

bool in_range(int x, int y){
    return 0<= x && 0<= y && x < n && y < n;
}

vector<pair<int,int>> find_group(){
    
    // 1. 그룹 구하기
    
    int visit[20][20];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visit[i][j] = 0;
        }
    }
    
    vector<vector<pair<int,int>>> group_group; // 그룹들 모임 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == 0 && board[i][j] > 0){ // 적어도 하나의 색상 포함

                int visit_zero[20][20];
                
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        visit_zero[i][j] = 0;
                    }
                }
                
                
                vector<pair<int,int>> group; // 해당 그룹 
                queue<pair<int,int>> q;
                int group_color = board[i][j];
                
                int rainbow = 0;
                
                q.push({i, j});
                visit[i][j] = 1;
                group.push_back({i, j}); 
                
                while(q.size()){
                    auto h = q.front(); q.pop();
                    int hx = h.first;
                    int hy = h.second;
                    
                    
                    for(int dir=0; dir<4; dir++){
                        int nx = hx + dx[dir];
                        int ny = hy + dy[dir];
                        
                        if(!in_range(nx,ny)) continue;
                        if(visit[nx][ny]) continue;
                        if(board[nx][ny] == -1) continue;
                        if(board[nx][ny] == -2) continue;
                        if(board[nx][ny] != group_color && board[nx][ny] != 0) continue;
                        if(board[nx][ny] == 0) {
                            if(visit_zero[nx][ny] == 1) continue;
                            rainbow++;
                            q.push({nx,ny});
                            group.push_back({nx,ny});
                            visit_zero[nx][ny] = 1;
                        }
                        if(board[nx][ny] != 0) {
                            visit[nx][ny] = visit[hx][hy] + 1;
                            q.push({nx,ny});
                            group.push_back({nx,ny});
                        }
                    }
                }
                
                // 그룹 생성 후 무지개 추가 
                group.push_back({rainbow, -1});
                group_group.push_back(group);
            }
        }
    }
    
    // 그룹 우선순위
    vector<tuple<int,int,int,int,int>> pr;
    
    for(int i=0; i<group_group.size(); i++){
        // 1. 크기가 가장 큰 블록, 2. 무지개 블록 수 큰 것, 행이 가장 큰 것, 열이 가장 큰 것 
        int size = group_group[i].size();
        
        if(size == 2) continue; // 크기가 1인 그룹은 무시 (레인보우 블록 포함)

        int rainbow = group_group[i].back().first;
        int row = group_group[i][0].first;
        int col = group_group[i][0].second;
        int idx = i;
        
        pr.push_back(make_tuple(size, rainbow, row, col, idx));
    }
    

    if(pr.size() == 0) {
        vector<pair<int,int>> tmp;
        return tmp;
    }
    
    sort(pr.begin(), pr.end());
    int group_idx = get<4>(pr.back());
    group_group[group_idx].pop_back();
    return group_group[group_idx];
}

void remove_all(vector<pair<int,int>> group){
    int cnt = 0;
    
    for(auto h : group){
        int hx = h.first;
        int hy = h.second;
        
        board[hx][hy] = -2;
        cnt++;
    }
    
    score += cnt * cnt;
}

void test_board(){
    cout << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void test_group(vector<pair<int,int>> group){
    cout << '\n';
    for(auto h : group){
        int hx = h.first;
        int hy = h.second;
        
        cout << hx << ' ' << hy << '\n';
    }
    
}


int main(){
    input();
    int T = 0;
    
    while(1){
        T++;
        // cout << T << '\n';
        
        // 1. 블록 그룹 찾기 + 블록 우선순위 고려
        vector<pair<int,int>> group = find_group();
        // test_board();
        // test_group(group);
        
        // 블록 그룹의 크기가 0이면 break;
        if(group.size() == 0) break;
        
        // 2. 그룹 블록 제거 + 스코어 더하기
        remove_all(group);
        // test_board();
        
        // 3. 격자 중력 작용
        gravity();
        // test_board();
        
        // 4. 반시계 방향 회전
        rotate();
        // test_board();
        
        // 5. 격자 중력 작용
        gravity();
        // test_board();

    }
    
    cout << score << '\n';
    
    return 0;
}