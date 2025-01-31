/*Runtime: 364 ms, faster than 35.72% of C++ online submissions for Daily Temperatures.
Memory Usage: 93 MB, less than 6.52% of C++ online submissions for Daily Temperatures.*/

//시간 복잡도 O(N)  N ~ 2N

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        
        // {temp, index}
        stack<pair<int,int>> not_solved;
        
        not_solved.push({temperatures[0],0});
        
        int p = 1;
        
        while(p!=n){
            pair<int,int> last = not_solved.top();
            // solve stack top
            while(last.first < temperatures[p]){
                ans[last.second] = p - last.second;
                not_solved.pop();
                if(not_solved.empty()) break;
                last = not_solved.top();  
            }
            not_solved.push({temperatures[p], p});
            p++;
        }
        
        
        
        return ans;
    }
};