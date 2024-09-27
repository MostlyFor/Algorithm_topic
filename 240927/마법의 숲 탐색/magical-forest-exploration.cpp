#include <iostream>
#include <queue>
using namespace std;

int R,C;
int K; // 정령의 수
vector<pair<int,int>> arr; //
int res;
int idx = 1; // 정령 인덱스 
int board[73][70];
int score_board[1001]= {}; // i번째 땅을 밟으면 몇 점 확보
int st = 1;

int dx[4] = {-1, 0 ,1 ,0};
int dy[4] = {0, 1, 0, -1};

// 북동남서 

// new init
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
    auto h = arr[idx];
    int out_dir = h.second; // 정령 탈출 방향
    // 출구 구현 후 
    int col = h.first; // 정령 출발 열
    int row = 1; 

    // (row, col) = 정령 중앙 좌표

    // 조금 어려운 부분은 처음 들어올 때 어떻게 처리할지? -> 그냥 세 칸 늘려서 생각하자
    
    // 처음은 무조건 들어감 (c)
    // 더 이상 움직일 수 없을 때까지 이동 !!
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
    board[out_x][out_y] = -idx;
    // 땅 점수 초기화
    score_board[idx] = row-2+1;
    
    // if(idx == 5) cout << row << ' ' << col << '\n' << out_dir << ' ' << out_x << ' ' << out_y << '\n';

    for(int kk=st; kk<=idx; kk++){
        for(int i=0; i<4; i++){
            int nx = out_x+dx[i];
            int ny = out_y+dy[i];
            if(nx<0 || ny <0 || nx >=R || ny >= C) continue;
            score_board[kk] = max(score_board[kk],max(score_board[abs(board[nx][ny])], row-2+1));
        }
    }
}

void to_out(){

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
            }
        }

        st = idx+1;
        return;
    }

    // 1. idx move
    // 갈 수 있는 곳을 모두 표시하고 출구로 이동?

    res += score_board[idx];

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

int main(){
    input();

    // K개의 정령 이동
    while(K--){
        // 정령이 끝까지 이동
        move();

        // if(idx > 4){        
        //board_check(); // - 일단 무브는 정상
        // }

        // 정령 탈출 함수
        to_out();

        //cout << res << '\n';


        idx++; // 이제 다음 정령 볼 차례
    }
    

    output();
    return 0;
}