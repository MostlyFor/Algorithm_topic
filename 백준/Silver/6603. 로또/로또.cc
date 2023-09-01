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

void f(vector<int> pct, int sm, int n, vector<int>& arr) {
    if (pct.size() == 6) {
        for (auto k : pct)
            cout << k << ' ';
        cout << '\n';

        return;
    }

    for (int i = sm; i < n; i++) {
        pct.push_back(arr[i]);
        f(pct, i + 1, n, arr);
        pct.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int n; cin >> n;
        if (n == 0) break;
        //6개

        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> tmp;
        f(tmp, 0, n, arr);

        cout << '\n';
    }

    return 0;
}