#include <iostream>
using namespace std;


int n;
int board[100000][3];
int dp[3];
int dp_tmp[3];
int dp2[3];
int dp2_tmp[3];

int main(){
    cin >> n;
    
    //
    for(int i=0; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        
        board[i][0] = a;
        board[i][1] = b;
        board[i][2] = c;
    }
    
    
    dp[0] = board[0][0];
    dp[1] = board[0][1];
    dp[2] = board[0][2];
    dp2[0] = -board[0][0];
    dp2[1] = -board[0][1];
    dp2[2] = -board[0][2];
    
    int next[3] = {-1, 0, 1};
    
    for(int i=1; i<n; i++){
        
        dp_tmp[0] = max(dp[0], dp[1]) + board[i][0];
        dp_tmp[1] = max(dp[0], max(dp[1], dp[2])) + board[i][1];
        dp_tmp[2] = max(dp[1], dp[2]) + board[i][2];
        
        dp2_tmp[0] = max(dp2[0], dp2[1]) - board[i][0];
        dp2_tmp[1] = max(dp2[0], max(dp2[1], dp2[2])) - board[i][1];
        dp2_tmp[2] = max(dp2[1], dp2[2]) - board[i][2];
    
        // dp와 dp_tmp 교환
        for(int k=0; k<3; k++){
            dp[k] = dp_tmp[k];
            dp2[k] = dp2_tmp[k];
        }
    }
    
    
    int x = -1e9;
    int y = 1e9;
    
    for(int i=0; i<3; i++){
        x = max(x, dp[i]);
        y = min(y, -dp2[i]);
    }
    
    cout << x << ' ' << y;
    
    return 0;
}