#include <iostream>
#include <vector>
using namespace std;

int m, t;
// 몬스터는 따로 관리하기 어려우므로 벡터로 관리
vector<pair<int,int>> monsters;
vector<int> monsters_dir;

vector<pair<int,int>> eggs;
vector<int> eggs_dir;

vector<int> best_move;


int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int pdx[4] = {-1, 0, 1, 0};
int pdy[4] = {0, -1, 0, 1};

int deathboard[4][4]; // 시체
int test_board[4][4];

int px, py; // 팩맨 위치 정보 

int turn;


void input(){
    cin >> m >> t;

    cin >> px >> py;
    px--; py--;

    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        monsters.push_back({a-1,b-1});
        int d; cin >> d;
        monsters_dir.push_back(d-1);
    }
}

// 1. 몬스터 복제 시도
void copy_monster(){
    for(auto mon : monsters){
        // 죽은 몬스터는 신경 안씀
        if(mon.first != -1){
            eggs.push_back(mon);
        }
    }

    for(auto d : monsters_dir){
        if(d != -1) eggs_dir.push_back(d);
    }
}

// 2. 몬스터 이동
void move(){
    for(int i=0; i<monsters.size(); i++){
        int x = monsters[i].first;
        int y = monsters[i].second;
        int d = monsters_dir[i];

        if(x == -1) continue; // 죽은 몬스터 처리

        

        for(int dir=0; dir<8; dir++){
            int nx = x + dx[(d+dir) % 8];
            int ny = y + dy[(d+dir) % 8];

            if(0 > nx || 0 > ny || 4<= nx || 4<=ny) continue; // 범위 밖을 나간 경우
            if(nx == px && ny == py) continue; // 팩맨이 있는 경우
            if(deathboard[nx][ny] > 0) continue; // 몬스터 시체가 있는 경우
            monsters[i].first = nx;
            monsters[i].second = ny;
            monsters_dir[i] = (d+dir)%8;
            break;
        }
    }
}


void test_monster(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            test_board[i][j] = 0;
        }
    }


    for(int i=0; i<monsters.size(); i++){
        int x = monsters[i].first;
        int y = monsters[i].second;
        test_board[x][y]++;
    }


    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << test_board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool is_out(int x, int y){
    return 0 > x || 0 > y || x >=4 || y>=4;
}

// 3. 팩맨 이동
void p_move(){

    int score = 0;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                int score_tmp = 0;
                int pnx = px + pdx[i];
                int pny = py + pdy[i];
                int pnnx = pnx + pdx[j];
                int pnny = pny + pdy[j];
                int pnnnx = pnnx + pdx[k];
                int pnnny = pnny + pdy[k];
                
                if(is_out(pnx, pny)) continue;
                if(is_out(pnnx, pnny))continue;
                if(is_out(pnnnx, pnnny)) continue;
            
                
                // 가능한 조합 중 최대 score 계산
                for(int mon=0; mon < monsters.size(); mon++){
                    int mx = monsters[mon].first;
                    int my = monsters[mon].second;

                    // 만약 해당 몬스터를 먹는다면
                    if((mx == pnx && my == pny) || (mx == pnnx && my == pnny) || (mx == pnnnx && my == pnnny)){
                        score_tmp++;
                    }
                }

                // cout << score_tmp << '\n';

                if(score < score_tmp) {
                    score = score_tmp;
                    best_move.clear();
                    best_move.push_back(i);
                    best_move.push_back(j);
                    best_move.push_back(k);
                }
            }
        }
    }

    //best_move 토대로 이동
    int pnx = px + pdx[best_move[0]];
    int pny = py + pdy[best_move[0]];
    int pnnx = pnx + pdx[best_move[1]];
    int pnny = pny + pdy[best_move[1]];
    int pnnnx = pnnx + pdx[best_move[2]];
    int pnnny = pnny + pdy[best_move[2]];
    for(int mon=0; mon < monsters.size(); mon++){
        int mx = monsters[mon].first;
        int my = monsters[mon].second;
        // 몬스터 죽음 처리
        if((mx == pnx && my == pny) || (mx == pnnx && my == pnny) || (mx == pnnnx && my == pnnny)){
            monsters[mon].first = -1;
            monsters_dir[mon] = -1;
            deathboard[mx][my] = 3;
        }
    }

    px = pnnnx;
    py = pnnny;
    
}

int main() {
    input();

    while(turn < t){

        // cout << turn << " 번째 " << '\n';
        // cout << px << ' ' << py << '\n';


        turn++;
        eggs.clear();
        eggs_dir.clear();
        best_move.clear();

        // test_monster();

        // 1. 몬스터 복제 시도
        copy_monster();

        // 2. 몬스터 이동
        move();

        // test_monster();

        // 3. 팩맨 이동
        p_move();

        // test_monster();


        // 4. 몬스터 시체 소멸
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(deathboard[i][j]) deathboard[i][j]--;

            }
        }


        // 5. 몬스터 복제 완성
        for(int i=0; i<eggs.size(); i++){
            monsters.push_back(eggs[i]);
            monsters_dir.push_back(eggs_dir[i]);
        }
    }

    int answer = 0;

    for(auto mon : monsters){
        if(mon.first != -1) answer++;
    }

    cout << answer;
    return 0;
}