class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        // 일단 각 문자가 몇번 등장하는지 확인
        int abcd[26] ={0,};
        
        for(auto ch : s) abcd[ch-'a']++;
        
        
        int n = s.size();
        
        // 현재 partition 문자
        string tmp = "";
        for(int i=0; i<n; i++){
            tmp += s[i];
            abcd[s[i]-'a']--;
            
            // 지금 tmp에 있는 문자들이 다른 곳에서 안나오는지 확인
            int sum = 0;
            for(auto ch : tmp) sum += abcd[ch-'a'];
            
            if(sum == 0){
                ans.push_back(tmp.size());
                tmp = "";
            } 
        }
        
        return ans;
    }
};