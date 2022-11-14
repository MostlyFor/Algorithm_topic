class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPal(string s){
        int size = s.size();
        
        for(int i=0; i<size;i++){
            if(s[i]!=s[size-1-i]) return false;
        }        
        
        return true;
    }
    
    void f(string& s,int index, vector<string> candidate){
        if(index == s.size()){
            ans.push_back(candidate);
            return;
        }
        
        for(int i=index; i<s.size();i++){
            string tmp = s.substr(index, i-index+1);
            if(isPal(tmp)){
                candidate.push_back(tmp);
                f(s,i+1,candidate);
                candidate.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> candidate;
        
        f(s,0,candidate);
        
        return ans;
    }
};