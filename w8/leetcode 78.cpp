class Solution {
    vector<vector<int>> ans;
public:
    void f(vector<int>& nums,int index, vector<int>& container){
        if(index==nums.size()) {
            ans.push_back(container); return;
        }
        
        f(nums,index+1,container);
        container.push_back(nums[index]);
        f(nums,index+1,container);
        container.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> container;
        f(nums,0,container);
        
        return ans;
    }
};