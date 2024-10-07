#include <iostream>
#include <queue>
using namespace std;

int R,C,K; 
vector<pair<int,int>> arr; // 정령 위치와 방향 정보
int res;
int idx = 1; // 정령 인덱스 
int board[73][70];
int st = 1;
bool isExit[73][70];
int x,y;
bool visited[73][70];

// 북동남서
int dx[4] = {-1, 0 ,1 ,0};
int dy[4] = {0, 1, 0, -1};

// 초기화 함수
void sync(int k, int x, int y){
    board[x][y] = k;
    board[x-1][y] = k;
    board[x+1][y] = k;
    board[x][y+1] = k;
    board[x][y-1] = k;
}

void input(){
    cin >> R >> C >> K;
    R += 3;

    // 골렘이 출발하는 열, 골렘의 출구 방향 정보
    arr.push_back({-1,-1}); // dummy
    for(int i=0; i<K; i++){
        int a, b; cin >> a >> b;
        
        // 열은 1부터 시작, 초기화
        arr.push_back({a-1,b});
    }
}

void output(){
    // 정령들이 최종적으로 위치한 행의 총합
    cout << res;
}

void move(){
    // 0. 정령 초기화
    auto h = arr[idx];
    int out_dir = h.second; // 정령 탈출 방향
    int col = h.first;
    int row = 1;

    // (row, col) = 정령 중앙 좌표

    while(1){
        // 1. 아래로 바로 내려갈 수 있는 경우
        if((row+2 < R) && board[row+2][col] == 0 && board[row+1][col-1] == 0 && board[row+1][col+1] == 0){
            board[row][col] = 0;
            board[row+1][col] = 0;
            board[row-1][col] = 0;
            board[row][col+1] = 0;
            board[row][col-1] = 0;

            row++;
            sync(idx, row, col);
        }
        // 2. 서쪽 방향으로 회전하면서 내려가는 경우 (출구는 반시계로 이동)
        else if(row+2 <R && col - 2 >= 0 && board[row][col-2] == 0 && board[row-1][col-1]==0 && board[row+1][col-1] ==0 && board[row+1][col-2]==0 && board[row+2][col-1] == 0) {
            board[row][col] = 0;
            board[row+1][col] = 0;
            board[row-1][col] = 0;
            board[row][col+1] = 0;
            board[row][col-1] = 0;
            row++;
            col--;
            out_dir = (out_dir-1+4)%4; 
            sync(idx, row, col);
        }
        // 3. 동쪽 방향으로 회전하면서 내려가는 경우 (출구는 시계로 이동)
        else if(row+2 < R && col+2 < C && board[row][col+2] == 0 && board[row-1][col+1]==0 && board[row+1][col+1] ==0 && board[row+1][col+2]==0 && board[row+2][col+1] == 0){
            board[row][col] = 0;
            board[row+1][col] = 0;
            board[row-1][col] = 0;
            board[row][col+1] = 0;
            board[row][col-1] = 0;

            row++;
            col++;
            out_dir = (out_dir+1+4)%4; 
            sync(idx, row, col);
        }

        // 4. 이동 불가능한 경우
        else{
            break;
        }
    }

    // 출구 board에 초기화
    int out_x = row+dx[out_dir];
    int out_y = col+dy[out_dir];
    
    isExit[out_x][out_y] = 1;
    x = row, y = col;
}

// 
void to_out(int x, int y){

    bool is_out = false;
    for(int i=0; i<3; i++){
        for(int j=0; j<C; j++){
            if(board[i][j] !=0 ) is_out=true;
        }
    }

    if(is_out){ // 만약 정령이 범위를 벗어낫다면? 해당 정령 무시하고 그냥 초기화
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                board[i][j] = 0;
                isExit[i][j] = 0;
            }
        }
        st = idx+1;
        return;
    }

    // 1. 해당 정령의 위치에서부터 bfs 시작
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            visited[i][j] = 0;
        }
    }

    queue<pair<int,int>> q;
    q.push({x,y});
    int deepest = 0;
    visited[x][y] = 1;

    // 방문조건 1. 현재랑 같은 id일 것
    while(q.size()){
        auto here = q.front(); q.pop();
        
        for(int dir =0; dir<4; dir++){
            int nx = here.first + dx[dir];
            int ny = here.second + dy[dir];

            if(0>nx || 0>ny || nx >= R || ny >= C) continue; // 범위 나갔다면
            if(visited[nx][ny]) continue; // 이전에 방문했다면
            if(board[here.first][here.second] == board[nx][ny] || isExit[here.first][here.second]){
                q.push({nx,ny});
                visited[nx][ny] = 1;
                deepest = max(deepest, nx-2);
            } // 현재랑 같은 id 이거나 출구일 것 



        }
    }

    res += deepest;
}


void board_check(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
}

void init(){
    x = 0; y = 0;
}

int main(){
    input();

    // K개의 정령 이동
    while(K--){
        move(); // 정령이 끝까지 이동

        // board_check();
        to_out(x, y); // 정령 점수 계산

        idx++; // 이제 다음 정령 볼 차례
        init();
    }
    
    output();
    return 0;
}