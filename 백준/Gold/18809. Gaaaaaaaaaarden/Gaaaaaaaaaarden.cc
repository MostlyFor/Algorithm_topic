#include <iostream>
#include <queue>
using namespace std;

int n, m, g, r;
int board_ori[50][50]; // 땅 , 3번 = 초록색, 4번 = 빨간색


vector<pair<int,int>> all_pos_board; // 2번 칸 
vector<int> cases;

int ans = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// 시뮬레이션에서 사용
vector<pair<int,int>> pos_board; // 배양액으로 사용할 땅
int visit[50][50];
int board[50][50];
int tmp_ans;

int cases_cnt_all = 0;
int cases_cnt = 0;

void simulate_input(){
    
    // 시뮬레이션에서 쓸 보드 초기화 (0과 1만 남음)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            board[i][j] = board_ori[i][j];
        }
    }
    
    // 거리 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visit[i][j] = 0;
        }
    }
    
    // map에 초록색과 빨간색 표시
    for(int i : cases){
        int x = pos_board[i].first;
        int y =pos_board[i].second;
        board[x][y] = 3;
    }
    
    for(int i=0; i<pos_board.size(); i++){
        int x = pos_board[i].first;
        int y =pos_board[i].second;
        if(board[x][y] == 3) continue;
        board[x][y] = 4;
    }
    
    
    tmp_ans = 0;
}


void simulate(){
    
    simulate_input();
    
    // bfs를 이용한 전염 알고리즘
    queue <pair<int,int>> q;
    for(auto k : pos_board) {
        q.push(k);
        visit[k.first][k.second] =1;
    }
    
    while(q.size()){
        auto h = q.front(); q.pop();
        int hx = h.first;
        int hy = h.second;
        if(board[hx][hy] == 1000) continue;
        
        for(int dir =0; dir<4; dir++){
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];
            if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;
            if(board[nx][ny]==0) continue; // board 가 0 인 경우
            if(board[nx][ny] == board[hx][hy]) continue; // 같은 색인 경우
            if(board[nx][ny] == 1000) continue; // 식물이 만들어진 경우
            if(board[nx][ny] == 1){ // 1인 경우
                board[nx][ny] = board[hx][hy];
                visit[nx][ny] = visit[hx][hy] + 1;
                q.push({nx,ny});
                continue;
            }
            // 색이 다른 경우
            if(visit[nx][ny] != visit[hx][hy] + 1) continue; // 처리하지 않아도되는 시간 
            else if(visit[nx][ny] == visit[hx][hy] + 1){
                visit[nx][ny] = -1;
                board[nx][ny] = 1000;
                tmp_ans++;
            }
        }
        
    }
    
    
    ans = max(ans, tmp_ans);
}



void get_cases(int idx){
    if(cases.size() == g){
        cases_cnt++;
        simulate();
        return;
    }
    
    for(int i=idx; i<pos_board.size(); i++){
        cases.push_back(i);
        get_cases(i+1);
        cases.pop_back();
    }
}

void get_all_cases(int idx){
    if(pos_board.size() == g+r){
        cases_cnt_all++;
        get_cases(0);
        return;
    }
    
    for(int i=idx; i<all_pos_board.size(); i++){
        pos_board.push_back(all_pos_board[i]);
        get_all_cases(i+1);
        pos_board.pop_back();
    }
}

void input(){
    cin >> n >> m >> g >> r;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board_ori[i][j];
            if(board_ori[i][j] == 2) {
                all_pos_board.push_back({i,j});
                board_ori[i][j] = 1;
            }
        }
    }
}

int main(){
    input();

    // all_pos_board에서 g+r개를 선택해서 pos_board
    get_all_cases(0);
    
    // cout << cases_cnt_all << '\n';
    // cout << cases_cnt << '\n';
    // -> 경우의 수는 문제가 없음
    
    cout << ans;
    
    return 0;
}