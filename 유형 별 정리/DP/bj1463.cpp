#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 첫 번째 풀이 dfs
// 시간복잡도 : O(N) : < N
// 공간복잡도 : O(N) : N

int dp[1000001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;

    queue<int> q;

    q.push(N);

    while (!q.empty()) {
        int h = q.front(); q.pop();
        if (h == 1) break;
        vector<int> n;
        n.push_back(h-1);
        if (h % 2 == 0)
            n.push_back(h/2);
        if (h % 3 == 0)
            n.push_back(h/3);
        for (auto k : n) {
            if (dp[k] < 0) continue;
            if (dp[k]) continue;
            dp[k] = dp[h] + 1;
            q.push(k);
        }
    }
    cout << dp[1];

    return 0;
}

// 두 번째 풀이 DP
// 시간복잡도 : O(N) : N
// 공간복잡도 : O(N) : N


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;

    dp[1] = 0;
    for (int i = 2; i < N + 1; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[1];

    return 0;
}