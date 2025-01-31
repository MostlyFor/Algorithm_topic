class Solution {
    map<char,vector<char>> dict;
    vector<string> ans;
    int n;
public:
    void f(string str, int idx, string digits){
        if(idx == n) {
            ans.push_back(str);
            return;
        }
        
        for(auto ch : dict[digits[idx]]){
            str.push_back(ch);
            f(str, idx+1, digits);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        dict['2'] = {'a','b','c'};
        dict['3'] = {'d','e', 'f'};
        dict['4'] = {'g', 'h', 'i'};
        dict['5'] = {'j', 'k', 'l'};
        dict['6'] = {'m', 'n', 'o'};
        dict['7'] = {'p','q','r','s'};
        dict['8'] = {'t','u','v'};
        dict['9'] = {'w','x','y','z'};
        
        vector<vector<char>> tmp;
        for(auto ch : digits) tmp.push_back(dict[ch]);
        
        n = digits.size();
        if(!n) return ans;
        f("", 0, digits);
        
        return ans;
    }
};