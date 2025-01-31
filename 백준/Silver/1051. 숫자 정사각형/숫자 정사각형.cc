#include <iostream>
#include <string>
using namespace std;

int n, m;
int board[50][50];
int ans = 0;

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str; cin >> str;
        
        for(int j=0; j<m; j++){
            board[i][j] = str[j] - '0';
        }
    }
}


bool f(int x, int y, int l){
    return x+l-1 < n && y+l-1 < m && board[x][y] == board[x+l-1][y] && board[x][y] == board[x][y+l-1] && board[x][y] == board[x+l-1][y+l-1];
}


int main(){
    input();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int limit = min(n, m);
            for(int l = 1; l <= limit; l++){
                
                if(f(i,j,l)){ // 정사각형 가능한 경우 
                    ans = max(ans, l);
                }
                
            }
        }
    }
    
    cout << ans * ans;
    
    return 0;
}