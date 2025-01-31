#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int dp[60001] ={0};
    for(int i=0; i<3; i++) dp[i] = i;
    
    for(int i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    
    return dp[n];
}