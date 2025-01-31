class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(1)
        int king = 0;
        int cattle = 0;
        
        for(auto k : nums){
            if(cattle == 0){
                cattle++;
                king = k;
            }
            
            else if(cattle && king == k) cattle++;
            else cattle--;
        }
        
        return king;

    }
};