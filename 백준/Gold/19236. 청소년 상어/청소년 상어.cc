#include <iostream>
using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int ans = -1; // 상어가 낼 수 있는 최고점

struct Fish{
    int x;
    int y;
    int dir;
    bool is_alive = true;
};

void input(int board[4][4], Fish fishes[]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a, b; cin >> a >> b;
            b--;
            board[i][j] = a;
            fishes[a].x = i;
            fishes[a].y = j;
            fishes[a].dir = b;
        }
    }
}

bool in_range(int x, int y){
    return 0<=x && 0<=y && x < 4 && y < 4;
}

void test_fishes(Fish fishes[17]){
    for(int i=1; i<17; i++){
        Fish fish = fishes[i];
        cout << fish.x << ' ' << fish.y << ' ' << fish.dir << '\n';
    }
    cout << '\n';
}

void test_board(int board[][4], Fish fishes[17]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void shark_move(Fish fishes[17], int board[4][4], int total_score, int sx, int sy, int sdir){
    // 재귀 상태 보존용
    Fish tmp_fishes[17];
    for(int i=0; i<=16; i++){
        tmp_fishes[i] = fishes[i];
    }
    
    int tmp_board[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            tmp_board[i][j] = board[i][j];
        }
    }
    
    // 1. 상어가 현재 위치 물고기 먹음 
    int eaten = tmp_board[sx][sy];
    tmp_board[sx][sy] = -1;
    total_score += eaten;
    sdir = tmp_fishes[eaten].dir;
    tmp_fishes[eaten].is_alive = false;
    
    // test_board(tmp_board);
    
    // 2. 물고기 이동
    for(int i=1; i<=16; i++){
        Fish& fish = tmp_fishes[i];
        if(fish.is_alive == false) continue;
        int hx = fish.x;
        int hy = fish.y;
        int dir = fish.dir;
        
        for(int cnt =0; cnt < 8; cnt++){
            int new_dir = (dir + cnt) % 8;
            
            int nx = hx + dx[new_dir];
            int ny = hy + dy[new_dir];
            
            if(!in_range(nx,ny)) continue;
            if(tmp_board[nx][ny] == -1) continue;  
            
            // 빈 공간인 경우
            if(tmp_board[nx][ny] == 0){
                tmp_board[hx][hy] = 0;
                tmp_board[nx][ny] = i;
                
                fish.x = nx;
                fish.y = ny;
                fish.dir = new_dir;
                break;
            }
            
            // 다른 물고기 있는 경우 
            else if(tmp_board[nx][ny] > 0){
                int j = tmp_board[nx][ny];
                Fish& new_fish = tmp_fishes[j];
                
                tmp_board[nx][ny] = i;
                tmp_board[hx][hy] = j;
                
                new_fish.x = hx;
                new_fish.y = hy;
                fish.x = nx;
                fish.y = ny;
                fish.dir = new_dir;
                break;
            }
        }
    }
    
    // test_board(tmp_board);
    
    ans = max(ans, total_score);
    // test_fishes(tmp_fishes);
    // // 3. 상어 이동
    for(int i=1; i<=3; i++){
        int nx = sx + i * dx[sdir];
        int ny = sy + i * dy[sdir];
        
        if(!in_range(nx,ny)) continue;
        if(tmp_board[nx][ny] == 0) continue; // 빈칸인 경우
        tmp_board[sx][sy] = 0;
        shark_move(tmp_fishes, tmp_board, total_score, nx, ny, sdir);
        tmp_board[sx][sy] = -1;
    }
    
    
}

int main(){
    // test_fishes();
    int board[4][4]; // -1 : 상어, 0 : 빈칸, k : 나머지 물고기들
    Fish fishes[17];
    input(board, fishes);
    shark_move(fishes, board, 0, 0, 0, 0);
    cout << ans << '\n';
    return 0;
}