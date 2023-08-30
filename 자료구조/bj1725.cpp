#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

//시간복잡도 O(2N)


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    arr.push_back(-1);

    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        int h = arr[i];
        int left = 1e9;
        // 높이가 낮아질 때
        while (!st.empty() && st.top().second > h) {
            auto x = st.top(); st.pop();
            ans = max(ans, (i - x.first) * x.second);
            left = min(x.first, left);
        }
        st.push({min(left,i), h});
    }
    cout << ans; 

    return 0;
}