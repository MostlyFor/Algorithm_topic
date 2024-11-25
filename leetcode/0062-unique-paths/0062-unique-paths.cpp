class Solution {

public:
    
    int dp[201][101] = {}; // dp[x][y] = x C y
    
    // x H y 계산 - x+y-1 C y = x+y-2 C y-1 + x+y-2 C y
    // dp[x][y] = x C y
    
    
    
    int uniquePaths(int m, int n) {
        
        
        // 어쨋든 m-1번 내려가야 하는데, 어디서 내려갈 것인지를 결정하는 문제
        
        // 선택할 수 있는 보기는 총 n개
        
        // 중복 조합  nHm-1 = (m-1) + (n) -1 C m-1 : n개의 색을 가진 공 중 m-1개를 고르는데 칸막이 비용 n-1 발생 
        
        // ex) 1 8C2 = 28
        
        // ex) 2 3C2 = 3
        
        
        // n C 0 = 1 
        // 0 C 0은?  1 C 1 = 0 C 0 + 0 C 1 = 1 따라서 0 C 0 = 1
        for(int i=0; i<=m-1+n-1; i++) dp[i][0] = 1;
        
        
        // n C x = n C (n-x) 이므로
        int k = m-1;
        if((m-1+n-1)/2 < m-1) k = n-1;
            
        for(int i=1; i<=m-1+n-1; i++){
            for(int j=1; j<=k; j++){
                if(i < j) continue;
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                
            }
        }
        
        
        
        
        return dp[m-1+n-1][k];
    }
};