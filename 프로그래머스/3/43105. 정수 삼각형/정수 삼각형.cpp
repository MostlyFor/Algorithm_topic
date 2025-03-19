#include <string>
#include <iostream>
#include <vector>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // dp[i][j] = 여기까지 왔을 때의 최대 합
    // dp[i][j] = max(dp[i-1][j], dp[i-1][j+1])  + tri[i][j]
    
    int level = triangle.size();
    
    dp[0][0] = triangle[0][0];
    
    for(int i=1; i<level; i++){
        for(int j=0; j<=i; j++){
            if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
    }
    
    for(int i=0; i<level; i++){
        answer = max(answer, dp[level-1][i]);
    }
    
    return answer;
}