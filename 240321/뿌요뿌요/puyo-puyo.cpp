#include <iostream>
#include <vector>
using namespace std;

int n;
int board[100][100];
int cnt_max = 0;
int ans = 0;

bool InRange(int x, int y){
    return 0<= x && 0 <= y && x<n && y<n;
}

// x, y와 인접한 개수 
int pop(int x, int y, int num){
    if(!InRange(x,y)) return 0;
    if(board[x][y]!= num) return 0;
    if(board[x][y] < 0) return 0;
    board[x][y] = -1;

    return 1 + pop(x+1,y,num) + pop(x,y+1,num) + pop(x-1,y,num) + pop(x,y-1,num);
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> board[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = pop(i,j, board[i][j]);
            cnt_max = max(cnt, cnt_max);
            if(cnt >= 4) ans++;
        }
    }

    cout << ans << ' ' << cnt_max;
    return 0;
}