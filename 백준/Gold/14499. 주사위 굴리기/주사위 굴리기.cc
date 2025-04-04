#include <iostream>
#include <tuple>
using namespace std;

int n, m;
int hx, hy, k;

int board[20][20];

int dice[7] = {0,0,0,0,0,0,0};
tuple<int,int,int> state;

int dx[4] = {0,0,-1,1}; // 동 서 북 남
int dy[4] = {1,-1,0,0};

void input(){
    cin >> n >> m;
    cin >> hx >> hy >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    
    state = make_tuple(1,5,3);
    //dice[6] = board[0][0];
}

bool in_range(int x, int y){
    return 0 <= x && 0 <= y && x < n && y < m;
}

void move(){
    int dir; cin >> dir; dir--;
    
    int nx = hx + dx[dir];
    int ny = hy + dy[dir];
    
    if(!in_range(nx, ny)) return;
    
    hx = nx; hy = ny;
    
    if(dir == 0) state = make_tuple(7-get<2>(state),get<1>(state), get<0>(state));
    if(dir == 1) state = make_tuple(get<2>(state),get<1>(state), 7-get<0>(state));
    if(dir == 2) state = make_tuple(get<1>(state), 7-get<0>(state), get<2>(state));
    if(dir == 3) state = make_tuple(7-get<1>(state),get<0>(state), get<2>(state));
    
    if(board[nx][ny] == 0) board[nx][ny] = dice[7 - get<0>(state)]; 
    else if(board[nx][ny]) {
        dice[7 - get<0>(state)] = board[nx][ny];
        board[nx][ny] = 0;
    }
    
    cout << dice[get<0>(state)] << '\n';

    
}

int main(){
    input();
    
    for(int i=0; i<k; i++) move();
    
    return 0;
}