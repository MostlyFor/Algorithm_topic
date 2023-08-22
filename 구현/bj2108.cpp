#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>

using namespace std;

// 시간복잡도 O()


bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    map<int, int> dict;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int sum = 0;
    for (auto k : arr) {
        sum += k;
        dict[k]++;
    }
    
    vector<pair<int, int>> tmp;
    for (auto it : dict) {
        tmp.push_back(it);
    }

    sort(tmp.begin(), tmp.end(),cmp);

    if (sum > 0) {
        if (((sum % n) * 1.0) / n >= 0.5) cout << sum / n + 1 << '\n';
        else cout << sum / n << '\n';
    }
    else {
        if ((abs(sum % n) * 1.0) / n > 0.5) cout << sum / n - 1 << '\n';
        else cout << sum / n << '\n';
    }
    cout << arr[n / 2] << '\n';

    if (n == 1) cout << arr[0] << '\n';
    else {
        if (tmp[0].second == tmp[1].second) cout << tmp[1].first << '\n';
        else cout << tmp[0].first << '\n';
    }
    cout << arr[n - 1] - arr[0] << '\n';

    return 0;
}