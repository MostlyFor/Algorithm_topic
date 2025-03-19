#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[41][121];

int solution(vector<vector<int>> info, int n, int m) {
    // dp[현재 단계][사용한 B의 흔적] = 0에서 현재 단계까지 오는데 필요한 A의 흔적
    for(int i=0; i<=info.size(); i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = 1e9;
        }
    }
    
    dp[0][0] = 0;
    
    // dp[i][j] : i까지 훔침
    for(int i=1; i<=info.size(); i++){
        for(int j=0; j<=m; j++){
            if(dp[i-1][j] >= n) continue;
            dp[i][j+info[i-1][1]] = dp[i-1][j]; // B를 사용한 경우
            dp[i][j] = min(dp[i-1][j] + info[i-1][0], dp[i][j]); // A를 사용한 경우
        }
    }
    
    
    int answer = 1e9;
    for(int i=0; i<m; i++){
        if(dp[info.size()][i] >= n) continue;
        answer = min(answer, dp[info.size()][i]);
    }
    if(answer==1e9) return -1;
    return answer;
}