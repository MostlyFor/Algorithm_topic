class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(1e9);
        
        if(nums[0] >= target) return 0;
        int st = 0; // 나보다 큼
        int ed = nums.size()-1; // 나보다 작음
        while(st+1 != ed){
            int mid = (st + ed)/2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target) st = mid;
            else ed = mid;
        }
        
        return ed;
    }
};