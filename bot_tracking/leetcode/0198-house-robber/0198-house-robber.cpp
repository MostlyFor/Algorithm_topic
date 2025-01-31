class Solution {
public:
    int rob(vector<int>& nums) {
        // 2칸 뛸수도 있고 한 칸 뛸수도 있다
        // 완전 탐색 해버릴 수도 있지만 dp 아이디어 응용해서 하나를 고정시켜버리는 것도 괜찮다.
        // dp[k] = k를 방문한 최대
        // dp[k] = max(dp[k-2] + nums[k], dp[k-3] + nums[k]);
        
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[1];
        if(n == 2) return max(dp[0], dp[1]);
        dp[2] = dp[0] + nums[2];
        if(n == 3) return max(dp[1],dp[2]);
        for(int i=3; i<n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-3] + nums[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};