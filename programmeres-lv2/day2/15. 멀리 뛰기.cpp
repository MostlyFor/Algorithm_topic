#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    // 1칸 또는 2칸 (1,2,1)과 (2,1,1)이 따로 세지므로
    // dp[k] = dp[k-1] + dp[k-2];
    int dp[2001];
    dp[1] = 1;
    dp[2] = 2;
    
    for(int k=3; k<=n; k++){
        dp[k] = dp[k-1] + dp[k-2];
        dp[k] %=1234567;
    }    
    
    
    return dp[n];
}