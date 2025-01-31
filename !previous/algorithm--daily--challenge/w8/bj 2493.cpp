#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
    stack<pair<int,int>> st;
    int n;
    cin >> n;
    vector<int> ans;
    //현재 가장 최근 스택의 인덱스
    int index = 0;

    // 스택이 비어버리면 무조건 0주면 됨.
    //현재 인덱스
    for(int i=0; i<n; i++){
        int rt;
        cin >> rt;


        //오르막인 경우 자신보다 큰게 나올 때 까지 스택 뽑음.
        while (!st.empty() && st.top().first < rt) {
            st.pop();
        }


        if (st.empty()) ans.push_back(0);
        else {
            ans.push_back(st.top().second);
        }
        st.push({ rt,i+1 });
        
    }



    for (auto v : ans)
        cout << v << ' ';

    return 0;
}