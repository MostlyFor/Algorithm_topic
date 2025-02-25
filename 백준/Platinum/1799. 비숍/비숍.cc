#include <iostream>
using namespace std;
int n; 
int bishop; // 해당 경우의 수에 놓을 수 있는 최대 비숍 수
int board[10][10];

int st = 1e9;
int minuss[19];

void f(int plus, int bs){
    
    if(2*n-2 - plus + bs < bishop) return;
    
    if(plus == 2*n-1){
        bishop = max(bishop, bs);
        return;
    }
    
    f(plus+1, bs);
    
    for (int y = max(0, plus - (n-1)); y <= min(plus, n - 1); y++){
        int x = plus - y;
        if(x < 0) break;
        if(board[x][y] == 0) continue; // 비숍 불가능
        if(minuss[x-y+n-1]) continue; // 비숍 불가능
    
        board[x][y] = 0;
        minuss[x-y+n-1] = 1;
        f(plus+1, bs+1);
        minuss[x-y+n-1] = 0;
        board[x][y] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j]) st = min(st, i+j);
        }
    }
    
    f(st, 0);
    
    cout << bishop;
    
    
    return 0;
}