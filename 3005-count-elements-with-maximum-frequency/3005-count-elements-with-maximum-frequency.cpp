class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> m;
        for(auto num : nums)
            m[num]++;
        
        int mf = 0;
        for(auto it : m){
            mf = max(mf, it.second);
        }
        int ans = 0;
        for(auto it : m){
            if(mf == it.second) ans += mf;
        }
        
        return ans;
    }
};