class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums){
        
        unordered_set<int> windows;
        int ans =0;
        
        vector<int> prefix_sum(nums.size(),0);
        
        //부분합 구하기 O(n)
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            prefix_sum[i]= sum;
        }
        
        //윈도우 정의하기
        auto left = prefix_sum.begin();
        auto right = prefix_sum.begin();
        
        auto start = prefix_sum.begin();
        
        sum = 0;
        
        //가능한 모든 윈도우 탐색 O(n)
        do{
            windows.insert(nums[right-start]);
            
            
            
            //가능한 윈도우마다 최대 크기 계산
            if(windows.size()==right-left+1){
                sum = max(sum, *right - *left + nums[left-start]);
                right++;
            }
            //불가능한 윈도우라면
            else{
                windows.erase(nums[left-start]);
                left++;   
            }
        }while(right!=prefix_sum.end());
        
        
        return sum;
        
        
    }
};