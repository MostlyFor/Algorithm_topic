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


// 시간복잡도 O(2 * 2^20 + N/4 *logN + 2^20 * log2^20)

vector<int> arr;
vector<int> w1;
vector<int> w2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    int a = arr.size() / 2;

    w1.push_back(0);
    w2.push_back(0);

    for (int i = 0; i < a; i++) {
        int cnt = w1.size();
        for (int j = 0; j < cnt; j++)
            w1.push_back(w1[j] + arr[i]);
    }

    for (int i = a; i < arr.size(); i++) {
        int cnt = w2.size();
        for (int j = 0; j < cnt; j++)
            w2.push_back(w2[j] + arr[i]);
    }

    sort(w2.begin(), w2.end());
    
    long long ans = 0;

    for (int i = 0; i < w1.size(); i++) {
        ans += lower_bound(w2.begin(), w2.end(), s - w1[i] + 1) - lower_bound(w2.begin(), w2.end(), s - w1[i]);
    }

    if (s == 0) ans--;
    cout << ans;

    return 0;
}