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

    int n, k; cin >> n >> k;

    queue<int> q;

    for (int i = 0; i < n; i++) q.push(i + 1);

    cout << '<';
    while (!q.empty()) {
        int cnt = k-1;
        while (cnt) {
            int tmp = q.front(); q.pop();
            q.push(tmp);
            cnt--;
        }
        if (q.size() == 1) break;
        cout << q.front() << ',' << ' ';
        q.pop();
    }

    cout << q.front() << '>';
    

    return 0;
}