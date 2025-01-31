class Solution {
    int dp[10001];
public:
    int numSquares(int n) {
        // dp[k]의 정의 = least number of perfect numbers that sum k
        
        for(int k=1; k<=n; k++) dp[k] = 1e9;
        
        for(int i=0; i * i <= n; i++){
            for(int k = i*i; k <=n; k++){
                dp[k] = min(dp[k], dp[k - i*i] + 1);            
            }
        }
        
        
        return dp[n];
    }
};