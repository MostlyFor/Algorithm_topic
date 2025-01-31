class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,1);
        vector<int> pre(n,1), suf(n,1);
        
        for(int i=1; i<n; i++){
            int j = nums.size() - i - 1;
            pre[i] = pre[i-1] * nums[i-1];
            suf[j] = suf[j+1] * nums[j+1];
        }
        
        
        for(int i=0; i<n; i++) arr[i] = pre[i] * suf[i];
        
        return arr;
    }
};