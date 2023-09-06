class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        
        vector<int> ans(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            
            while(!st.empty()){
                if(temperatures[st.top()] >= temperatures[i]){
                    break;
                } 
                int k = st.top(); st.pop();
                ans[k] = i-k;
            }
            st.push(i);
        }

        return ans;
    }
};