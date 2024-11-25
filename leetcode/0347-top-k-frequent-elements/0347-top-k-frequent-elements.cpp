class Solution {
public:
    // True면 p1, p2
    static bool cmp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second > p2.second) return true;
        else if(p1.second == p2.second && p1.first > p2.first) return true;
        return false;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        //O(N)
        for(auto num : nums) m[num]++;
        
        // {1,3} {2,2} {3,1}
        // value 기반 정렬
        vector<pair<int,int>> v;
        
        for(auto it : m) v.push_back(it);
        
        sort(v.begin(), v.end(), cmp);
        
        vector<int> ans;
        int i = 0;
        while(k--) ans.push_back(v[i++].first);
        
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (int num : nums)
//             ++m[num];
        
//         vector<vector<int>> buckets(nums.size() + 1); 
//         for (auto p : m)
//             buckets[p.second].push_back(p.first);
        
//         vector<int> ans;
//         for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
//             for (int num : buckets[i]) {
//                 ans.push_back(num);
//                 if (ans.size() == k)
//                     break;
//             }
//         }
//         return ans;
//     }
// };