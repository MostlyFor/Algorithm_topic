class Solution {
    vector<vector<int>> ans;
public:
    
    void f(vector<int>& nums, int idx){
        if(nums.size() == idx) {
            ans.push_back(nums);
        }
        
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            f(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums, 0);
        return ans;
    }
};