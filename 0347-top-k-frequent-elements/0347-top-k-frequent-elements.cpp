class Solution {
public:
    static bool cmp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second > p2.second) return true;
        else if(p1.second == p2.second && p1.first > p2.first) return true;
        return false;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        //nlgn
        for(auto num : nums) m[num]++;
        
        // {1,3} {2,2} {3,1}
        // value 기반 정렬
        vector<pair<int,int>> v;
        
        for(auto it : m) v.push_back(it);
        
        sort(v.begin(), v.end(), cmp);
        
        vector<int> ans; 
        int i = 0;
        while(k--){
            ans.push_back(v[i++].first);
        }
        
        return ans;
    }
};