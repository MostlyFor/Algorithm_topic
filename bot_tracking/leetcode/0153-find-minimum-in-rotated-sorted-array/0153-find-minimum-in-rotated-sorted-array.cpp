class Solution {
public:
    int findMin(vector<int>& nums) {
        
        
        // 배열이 끊겨 있지 않다면 그냥 첫번째 값
        int l = 0;
        int r = nums.size()-1;
        
        if(nums[l] == nums[r] || nums[l] < nums[r]) return nums[l];
        
        // 배열이 중간에 끊겨 있다면 가장 낮은 부분 log N
        while(l < r){
            int mid = (l + r)/2;
            
            if(nums[l] <= nums[mid]){
               if(nums[l] < nums[0]){
                   return nums[l];
                }
                l = mid+1;
            } 
            
            else r = mid;
        }
        
        
        return nums[l];
        
    }
};