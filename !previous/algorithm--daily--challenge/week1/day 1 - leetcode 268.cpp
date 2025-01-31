#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 배열 크기 만큼 서로 다른 숫자가 있음. 0 ~ n 중 n개 있음.
        // 0 ~ n 중 없는 숫자 return
        // space O(1), time O(n)에 해결해야함.
        
        int n = nums.size();
        
        int sum = (n*n + n)/2;
        int missing_sum = 0;
        
        for(auto i : nums)
            missing_sum+=i;
        
        
        return sum - missing_sum;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 배열 크기 만큼 서로 다른 숫자가 있음. 0 ~ n 중 n개 있음.
        // 0 ~ n 중 없는 숫자 return
        // space O(1), time O(n)에 해결해야함.
        
        int n = nums.size();
        
        int xor_ = 0;

        for(int i=0; i<n; i++)
            xor_^=nums[i]^i;
        
        
        return xor_^n;;
    }
};
