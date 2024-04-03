class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map <string, vector<int>> hmap; // key, idx 모음
        
        // O(N)
        for(int i=0; i<strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            
            // 만약 해당 값 존재 key 추가
            if(hmap.find(key) != hmap.end()){
                hmap[key].push_back(i);
            }
            
            else {
                vector<int> tmp;
                tmp.push_back(i);
                hmap[key] = tmp;
            }            
        }
        
        
        vector<vector<string>> ans;
        
        // O(N)
        for(auto it : hmap){
            vector<string> tmp;
            for(auto idx : it.second)  
                tmp.push_back(strs[idx]);
            ans.push_back(tmp);
        }
    
        return ans;
    }
    
};