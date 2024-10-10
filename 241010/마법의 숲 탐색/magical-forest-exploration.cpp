#include <iostream>
#include <queue>
using namespace std;

int R, C, K; 
int answer; // 최종 정답
int board[73][70]; // 골렘의 위치 정보를 저장 + 출구를 음수로 저장할 수도 있음
int idx = 0; // 골렘 번호
int fx, fy;

// 북 동 남 서 
int dx[4] = {-1,0,1,0};
int dy[4] = {0, 1, 0, -1};

// 정해진 출구


void input(){
    cin >> R >> C >> K;
    R+=3;
}

void fill_board(int x, int y, int k){
    board[x][y] = k;
    for(int dir=0; dir<4; dir++) board[x+dx[dir]][y+dy[dir]] = k;
}

// 해당 위치가 0인지 판단
bool is_zero(int x, int y){
    bool is_in = 0<=x && 0<=y && x<R && y<C;
    if(is_in && board[x][y] == 0) return true; 
    return false;
}

// 1. 골렘 이동
void move_stone(int x, int y, int stone_dir){
    bool is_pos = true;
    fill_board(x,y,idx);
    
    while(is_pos){
        // 1-1. 남쪽 이동
        if(is_zero(x+2,y) && is_zero(x+1,y+1) && is_zero(x+1,y-1)){
            fill_board(x,y,0);
            x++;
            fill_board(x,y,idx);
        }

        // 1-2. 서쪽으로 이동
        else if(is_zero(x,y-2) && is_zero(x-1,y-1) && is_zero(x+1,y-1) && is_zero(x+2,y-1) && is_zero(x+1,y-2)){
            fill_board(x,y,0);
            x++; y--;
            fill_board(x,y,idx);
            stone_dir = (stone_dir+3)%4;
        }

        // 1-3. 동쪽으로 이동
        else if(is_zero(x,y+2) && is_zero(x-1,y+1) && is_zero(x+1,y+1) && is_zero(x+2,y+1) && is_zero(x+1,y+2)){
            fill_board(x,y,0);
            x++; y++;
            fill_board(x,y,idx);
            stone_dir = (stone_dir+1)%4;
            
        }

        // 1-4. 이동 불가
        else is_pos = false;
    }

    // 1-5. 골렘 출구 갱신
    board[x+dx[stone_dir]][y+dy[stone_dir]] *=-1;

    fx = x;
    fy = y;
}

// 2. 요정 이동
void move_fire(){
    int deepest = 0;

    queue<pair<int,int>> q;
    int visited[73][70];
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) visited[i][j] = 0;
    
    q.push({fx,fy});
    visited[fx][fy] = 1;
    deepest = fx;

    while(q.size()){
        auto h = q.front(); q.pop();
        int hx = h.first;
        int hy = h.second;


        // bfs 이동 조건 1. 같은 번호거나 2. 해당 위치가 출구
        for(int dir=0; dir<4; dir++){
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];
            
            if(0 > nx || 0 > ny || nx >= R || ny >= C) continue;
            if(visited[nx][ny]) continue;

            if((abs(board[hx][hy]) == abs(board[nx][ny])) || (board[hx][hy] < 0 && board[nx][ny] != 0)){

                //cout << hx << ' ' << hy << ' ' << nx << ' ' << ny << '\n';
                q.push({nx,ny});
                visited[nx][ny] = 1;
                deepest = max(deepest, nx);
            }
        }
    }

    answer += deepest-2;
}

void test_board(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n'; 
    }
    cout << '\n';
}

void clear_board(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            board[i][j] = 0;
        }
    }
    
}

int main(){
    input();

    for(int i=0; i<K; i++){
        idx++; fx = 0; fy = 0;

        // c 열 해당 골렘 출구 방향 d
        int c, d; cin >> c >> d;
        c--;

        // 1. 골렘 이동
        move_stone(1, c, d);

        // test_board();

        // 2. 골렘 이동 실패 시 초기화
        if(fx-1 <= 2) {
            clear_board();
            continue;
        }

//        test_board();

        // 2. 정령 이동
        move_fire();

    }

    cout << answer;

    return 0;
}