#include <iostream>
#include <vector>
using namespace std;

int L; // 체스판 크기
int board[40][40]; // 체스판 1 함정, 2 벽
int playboard[40][40]; // 기사 번호들로 있는 곳들
int next_playboard[40][40]; // 이동했을 때의 보드
int life[31]; // 기사 체력 저장
int life_init[31]; // 기사 초기 체력 저장

int hit[31];
int visited[31];

int N, Q; // 기사의 수, 명령의 수

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;



void input(){
    cin >> L >> N >> Q;

    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N; i++){
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        for(int x=a-1; x<a-1+c; x++){
            for(int y=b-1; y<b-1+d; y++){
                playboard[x][y] = i+1;
            }
        }

        life[i+1] = e; // 기사 체력
        life_init[i+1] = e; // 기사 체력

    }
}

void test_playboard(){
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cout << playboard[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void test_next_playboard(){
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cout << next_playboard[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void test_life(){
    for(int i=1; i<=N; i++) cout << life[i] << ' ';
    cout << '\n';
}

bool isin(int x, int y){
    return 0<=x && 0<=y && x < L && y <L;
}

// 함수 이동시키는 함수 (a번 기사 dir 방향으로 이동)
bool can_move(int a, int dir){

    visited[a] = 1;

    int pos = true;

    // 1. 이동이 불가능한 경우 or 마주치는 기사 번호 가져오기
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            // 이동이 불가능한 경우 (벽을 만났거나 범위 밖이거나 )
            if(playboard[i][j] == a && (!isin(i+dx[dir], j+dy[dir]) || (board[i+dx[dir]][j+dy[dir]] == 2))){
                pos = false;
                continue;
            } 
            
            // 마주치는 기사 번호 - a 다음 칸이 0또는 a가 아님
            if(playboard[i][j] == a && (playboard[i+dx[dir]][j+dy[dir]] != a) && (playboard[i+dx[dir]][j+dy[dir]] != 0)){
                hit[playboard[i+dx[dir]][j+dy[dir]]] = 1;
            } 
        }
    }

    
    if(pos==false) return false;

    
    for(int i=1; i<=N; i++) {
        if(hit[i] && visited[i] == 0){
            // cout << i << ' ';
            // cout << 'h' << ' ' << i << '\n';
            visited[i] = 1;
            pos &= can_move(i, dir);
        }
    }


    return pos;
}

void init(){
    for(int i=1; i<=N; i++) {
        hit[i] = 0;
        visited[i] = 0;
    }
}

// 칸을 하나씩 이동시키는 함수
void move(int dir){
    // next_playboard 초기화
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            next_playboard[i][j] = 0;  // 이동할 상태 초기화
        }
    }


    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            // 한 칸씩 이동해야 하는 애들은 한 칸씩 이동
            if(hit[playboard[i][j]]){
                next_playboard[i+dx[dir]][j+dy[dir]] = playboard[i][j];
            }
            // 여기서 덮어써짐
            else if(playboard[i][j]) next_playboard[i][j] = playboard[i][j];
        }
    }

    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            // 한 칸씩 이동해야 하는 애들은 한 칸씩 이동
            playboard[i][j] = next_playboard[i][j];
        }
    }
    
}

int main() {
    input();
    

    // a 번 기사를 b 방향으로 한 칸 이동 (a 1~ )
    for(int i=0; i<Q; i++){
        int a, dir; cin >> a >> dir;

        // 기사 정보를 어디에? 
        // 판단 1 : board에 기사 표시를 하게되면 벽이랑 함정은 어떻게 하려구? 이건 어차피 계속 안바뀌는거니까 그냥 냅두고 기사를 이동을 따로 시켜야할 것 같은데? 


        // 1. 기사 이동
        // 이동하는 위치에 다른 기사 있다면 연쇄적으로 한 칸 밀려남 -> 재귀로 구현 가능
        // 판단 2 : 내가 볼 때 이거 구현은 재귀가 맞고 함수 기능은 간단하게 체크를 하고 가능한지 안가능한지 return 하는 함수면 될 것 같다. 이동은 마지막에 시키는거로 
        // 연쇄적으로 이동하다가 벽이 있다면 이동할 수 수 없음
        // 사라진 기사에게 명령 내리면 반응 x

        // 보드에서 a번에 해당하는 칸들을 하나 이동시키기 
        // 이동하면서 만난 번호들 하나씩 이동시키기 + 체스판 밖은 벽으로 구성

        
        init();

        // test_playboard();

        if(can_move(a, dir)){
            hit[a] = 1;
            hit[0] = 0;
            move(dir);
            hit[a] = 0;
        }
        else continue;
        
        
        // 2. 대결 대미지 - 최후로 밀려진 위치에 대해 피해 받음

        // test_playboard();

        // 함정이 있는 기사 번호에 대해서 life 감소
        for(int i=0; i<L; i++){
            for(int j=0; j<L; j++){
                if(board[i][j]==1){
                    if(hit[playboard[i][j]]==0) continue; // 움직이지 않은 기사는 피해 x
                    life[playboard[i][j]]--;
                }
            }
        }

        // test_life();


        
        // 현재 체적 이상의 대미지를 받을 경우 사라짐
        for(int i=1; i<N; i++){
            if(life[i] <= 0 && hit[i]){ // 기사 제거
                for(int x=0; x<L; x++){
                    for(int y=0; y<L; y++){
                        if(playboard[x][y]==i) playboard[x][y] = 0;
                    }
                }
            }
        }

        // test_life();
    }


    // test_life();
    
    for(int i=1; i<=N; i++){
        if(life[i]) {
            ans += life_init[i] - life[i];
        }
    }

    cout << ans;
    return 0;
}