class Solution {
public:
    // O(N)
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int mf = 0;
        int tf = 0;
        for(auto num : nums){
            m[num]++;
            int f = m[num];
            
            // 최대 freq가 새로 갱신
            if(mf < f) {
                mf = f;
                tf = mf;
            }
            
            // 최대 freq가 새로 갱신 x
            else if(mf > f)
                continue;
            
            else tf += mf;
            
        }
        
        return tf;
    }
};