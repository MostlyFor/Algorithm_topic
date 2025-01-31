/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.4 MB, less than 10.01% of C++ online submissions for Valid Parentheses.
*/


class Solution {
public:
    bool isValid(string s) {
        stack<int> last;
        
        for(auto c : s){
            if(c == '{' || c == '(' || c == '[')
                last.push(c);
            else{
                if(last.empty()) return false;
                char tmp = last.top();
                last.pop();
                if(tmp+1 != c && tmp+2 != c) return false;
            }
        }
        
        if(!last.empty()) return false;
        
        return true;
    }
};