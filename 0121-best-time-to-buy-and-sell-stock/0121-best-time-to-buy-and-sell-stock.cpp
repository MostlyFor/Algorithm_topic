class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // for 2번 완전탐색 -> 10^5 -> O
        int profit = 0;
        int low = prices[0];
        int high = prices[0];
        for(int i=0; i<prices.size(); i++){
            // 만약 고점이 갱신되는 경우
            if(high < prices[i]) high = prices[i];
            else if(high > prices[i]){
                profit = max(profit, high-low);
                high = prices[i];
                if(low > prices[i]) low = prices[i]; 
            }
        }
        profit = max(profit, high-low);
        return profit;
    }
};