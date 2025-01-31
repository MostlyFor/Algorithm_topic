class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto k : nums){
            sum ^=k;
        }
        return sum;
    }
};