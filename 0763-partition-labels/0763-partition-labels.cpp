class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        
        // 해당 알파벳이 언제 가장 마지막에 나오는지
        vector<int> abcd(26,-1);
        
        int n = s.size();
        
        // 가장 마지막에 나오는 인덱스 위치 저장
        for(int i=0; i<n; i++) abcd[s[i]-'a'] = i;
        
        
        // 최소한 여기까지는 나와야 함
        int limit = -1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            limit = max(abcd[s[i]-'a'], limit);
            cnt++;
            if(limit == i){
                ans.push_back(cnt);
                limit = -1;
                cnt = 0;
            }
        }
        
        return ans;
    }
};