#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, K; 
int board[73][70] = {}; // 0~2칸은 처음 시작하는 값
int exitt[73][70] = {};
int visited[73][70] = {};
int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[4] = {0, 1, 0, -1};

vector<pair<int,int>> stones; // 골렘 정보
int idx = 1, x, y, d; // 현재 턴의 골렘의 출구 방향 

int answer = 0; // 포인트 합계


void input(){
    // 숲의 크기와 정령 수
    cin >> R >> C >> K;
    R+=3;

    // 골렘이 출발하는 열과 출구 방향 정보
    for(int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;
        stones.push_back({a,b});
    }
}

void output(){
    cout << answer;
}

void sync(int tx, int ty, int qq){
    board[tx][ty] = qq;
    for(int dir = 0; dir <4; dir++) board[tx+dx[dir]][ty+dy[dir]] = qq;
}

bool is_zero(int hx, int hy){
    return 0<= hx && 0<= hy && hx<R && hy<C && board[hx][hy] ==0;
}

// 골렘 이동 함수
void move(){

    // 1. 끝까지 이동
    while(1){
        // 1. 일자로 내려가는게 가능한 경우
        if(is_zero(x+2,y) && is_zero(x+1,y+1) && is_zero(x+1,y-1)){
            sync(x,y,0);
            x++;
            sync(x,y,idx);
        }
        // 2. 서쪽으로 회전하면서 내려가는게 가능한 경우 (출구 회전)
        else if(is_zero(x,y-2) && is_zero(x-1,y-1) && is_zero(x+1, y-1) && is_zero(x+2,y-1) && is_zero(x+1,y-2)){
            sync(x,y,0);
            x++; y--;
            sync(x,y,idx);
            d = (d+3) % 4;
        }

        // 3. 동쪽으로 회전하는게 가능한 경우 (출구 회전)
        else if(is_zero(x,y+2) && is_zero(x-1,y+1) && is_zero(x+1, y+1) && is_zero(x+2,y+1) && is_zero(x+1,y+2)){
            sync(x,y,0);
            x++; y++;
            sync(x,y,idx);
            d = (d+1) % 4;
        }

        // 4. 이동이 불가능한 경우
        else
            break;
    }

    // 2. 출구 좌표 확정
    exitt[x+dx[d]][y+dy[d]] = 1;

}

void get_point(){
    
    // 1. 만약 해당 골렘이 0~2 사이에 있을 경우 무효 처리
    bool is_out = false;

    for(int i=0; i<3; i++){
        for(int j=0; j<C; j++){
            if(board[i][j] != 0) is_out = true;
        }
    }

    if(is_out){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                board[i][j] = 0;
                exitt[i][j] = 0;
            }
        }

        return;
    }

    // 2. 정령이 움직일 수 있는 가장 아래 위치 찾기 - bfs
    int deepest = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            visited[i][j] = 0;
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(q.size()){
        auto here = q.front(); q.pop();
        
        for(int dir =0; dir<4; dir++){
            int nx = here.first + dx[dir];
            int ny = here.second + dy[dir];
            
            if(0> nx || 0> ny || nx >= R || ny >=C) continue;
            if(visited[nx][ny]) continue;
            if((board[here.first][here.second]== board[nx][ny]) || (board[nx][ny]!=0 && exitt[here.first][here.second])){
                q.push({nx,ny});
                visited[nx][ny] = 1;
                deepest = max(deepest, nx -2);
            }
        }
    }
    
    answer += deepest;
    
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

void test_visited(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void test_exit(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << exitt[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    input();

    while(idx <= K){
        x = 1;
        y = stones[idx-1].first -1; // 열 방향 
        d = stones[idx-1].second;

        move(); // 골렘 이동 함수

        // test_board();

        get_point(); // 정령 점수 계산 함수
        // test_visited();
        // test_exit();

        // cout << answer << '\n';

        idx++;
        x = 0; y = 0; d = 0;
    }

    output();
    return 0;
}