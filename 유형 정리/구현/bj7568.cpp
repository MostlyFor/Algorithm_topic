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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p.push_back({ a,b });
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((p[i].first < p[j].first) && (p[i].second < p[j].second)) cnt++;
        }
        cout << cnt+1 << ' ';
    }

    return 0;
}