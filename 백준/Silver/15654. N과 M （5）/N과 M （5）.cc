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
vector<int> arr;
int n, m;
vector<int> check;
void f(vector<int>& now) {
    if (now.size() == m) {
        for (auto k : now)
            cout << k << ' ';
        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        now.push_back(arr[i]);
        check[i]++;
        f(now);
        now.pop_back();
        check[i]--;

    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    check.resize(n, 0);

    sort(arr.begin(), arr.end());
    vector<int> tmp;
    f(tmp);

    return 0;
}