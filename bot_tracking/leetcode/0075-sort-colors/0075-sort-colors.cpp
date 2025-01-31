class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last = nums.size()-1; // 2를 채워야 하는 곳
        int first = 0; // 0을 채워야 하는 곳
        int i = 0;
        
        while(i<=last){
            if(nums[i] == 0) {
                swap(nums[first++], nums[i]);
                i = first; continue;
            }
            if(nums[i] == 2) {
                swap(nums[last--],nums[i]);
                continue;
            }
            i++;
        }
        
    }
};