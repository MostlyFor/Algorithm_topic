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


// 시간복잡도 O(NlogN)
// 공간복잡도 O(N)


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> parr;
    vector<int> narr;
    int pcnt = 0;
    int ncnt = 0;
    int zcnt = 0;
    int ocnt = 0;
    int max_n = -1001;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (tmp > 1) {
            pcnt++;
            parr.push_back(tmp);
        }
        if (tmp == 0) {
            zcnt++; continue;
        }
        if (tmp == 1) {
            ocnt++; continue;
        }
        if (tmp < 0) {
            ncnt++;
            max_n = max(max_n, tmp);
            narr.push_back(-tmp);
        }
    }

    sort(parr.begin(), parr.end());
    int ans = 0;
    for (int i = parr.size() - 1; i >= 1; i -= 2) {
        ans += parr[i] * parr[i - 1];
    }

    if (parr.size() % 2) ans += parr[0];

    sort(narr.begin(), narr.end());

    for (int i = narr.size() - 1; i >= 1; i -= 2) {
        ans += narr[i] * narr[i - 1];
    }

    if (zcnt==0 && (ncnt%2)) ans -= narr[0];


    cout << ans + ocnt;

    return 0;
}