class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // 가장 무식하게는 O(2^(n+m)) 또는 O(2^(max(n+m) + 1))
        // 따로 따로 구하고 매칭하는 방법은 비효율적이라 상대방의 정보도 고려해야한다.
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // dp[n][m] : text1이 n까지 주어졌을 때, text2가 m까지 주어졌을 때의 LCS
        // dp[n+1][m+1] = dp[n][m] + 1 (문자가 같다면), 다르다면 그대로
         
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // dp 시각화
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        return dp[n][m];
    }
};