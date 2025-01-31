class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(max_idx < i) return false;
            max_idx = max(max_idx, i + nums[i]);
        }
        
        return nums.size()-1 <= max_idx;
    }
};