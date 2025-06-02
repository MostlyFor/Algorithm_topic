#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

long long dp[501][501][2]; // [i][j][dir] : i, j까지 오는데 dir 방향으로 옴 dir = 0 아래, dir = 1 오른쪽

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) for(int dir=0; dir<2; dir++) dp[i][j][dir] = 0;
    int answer = 0;
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    
    
    // 1열 경우의 수 - 아래로 내려가기
    for(int i = 1; i<m; i++){
        if(city_map[i][0] == 1) continue;
        dp[i][0][0] = dp[i-1][0][0];
    }
    
    for(int j=1; j<n; j++){
        if(city_map[0][j] == 1) continue;
        dp[0][j][1] = dp[0][j-1][1];
    }

    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(city_map[i][j] == 1) continue; // 해당 자리 차 접근 금지
            
            dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0];
            dp[i][j][0] = dp[i-1][j][1] + dp[i-1][j][0];
            
            if(city_map[i][j-1] == 2) dp[i][j][1] -= dp[i][j-1][0];
            if(city_map[i-1][j] == 2) dp[i][j][0] -= dp[i-1][j][1];
            
            
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    }
    
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             cout << dp[i][j][0] << ' ';
//         }
//         cout << '\n';
//     }
    
//     cout << '\n'    ;
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             cout << dp[i][j][1] << ' ';
//         }
//         cout << '\n';
//     }
    
    
    return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
}