#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[100][100]; // dp[i][j] : i, j 까지 오는 최단경로의 수

int solution(int m, int n, vector<vector<int>> puddles) {
    // 상태가 중복되기에 dp 사용
    
    for(auto p : puddles) dp[p[0]-1][p[1]-1] = -1;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            
            if(i == 0 && j == 0) dp[i][j] = 1;
            else{
                if(i == 0) dp[i][j] = dp[i][j-1];
                else if(j == 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
    }
    
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             cout << dp[i][j] << ' ';
//         }
//         cout << '\n';
//     }
    
    
    return dp[m-1][n-1];
}