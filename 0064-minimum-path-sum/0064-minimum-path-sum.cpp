class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        // dp[i][j] : i,j에서 시작해서 오른쪽 아래에 도달했을 때의 합
        
        vector<vector<int>> dp(r, vector<int>(c,0));
        
        dp[r-1][c-1] = grid[r-1][c-1];
        for(int i = r-2; i>=0; i--){
            dp[i][c-1] = grid[i][c-1] + dp[i+1][c-1];
        }
        
        for(int j= c-2; j>=0; j--){
            dp[r-1][j] = grid[r-1][j] + dp[r-1][j+1];
        }
        
        for(int i=r-2; i>=0; i--){
            for(int j = c-2; j>=0; j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        
        return dp[0][0];
    }
};