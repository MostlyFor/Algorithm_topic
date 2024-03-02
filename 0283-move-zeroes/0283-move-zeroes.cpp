class Solution {
public:
    // i 번째 
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void moveZeroes(vector<int>& nums) {
        // 0 0 0 0 1 2 3 4
        // 배열 최대값
        int limit = nums.size()-1;
        
        for(int i = limit; i>=0; i--){
            // 배열 오른쪽 값 0
            if(nums[i] == 0){
                // 0 오른쪽에 0이 있는지 확인
                for(int j=i+1; j<=limit; j++){
                    if(nums[j] != 0){
                        swap(nums, j-1, j);
                    }
                }
                limit--;
            }
        }
    }
};