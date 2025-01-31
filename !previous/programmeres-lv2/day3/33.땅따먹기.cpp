#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int r = land.size();
    vector<vector<int>> dp(r+1,vector<int>(4,0));
    
    
    for(int i=1; i<=r; i++){
        for(int j=0; j<4; j++){
            int alpha = 0;
            for(int k=0; k<4; k++){
                if(j==k) continue;
                alpha = max(alpha, dp[i-1][k] + land[i-1][j]);
            }
            dp[i][j] =alpha;
        }
    }
    
    for(int i=0; i<4; i++)
        answer = max(answer,dp[r][i]);
    
    return answer;
}