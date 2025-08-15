#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, start = 0;
int costMat[16][16];
int FULL;
int dp[1<<16][16]; // dp[mask][u] = mask 방문 후 u에 도달한 최소 비용 (도달 의미, prefix)

// top-down: dp[mask][u] 반환
int solveDP(int mask, int u) {
    if (!(mask & (1<<u))) return INF;              // u는 mask에 반드시 포함
    int &ret = dp[mask][u];
    if (ret != -1) return ret;

    // 기저: 시작점만 방문한 상태
    if (mask == (1<<start)) return ret = (u == start ? 0 : INF);

    ret = INF;
    int prevMask = mask ^ (1<<u);                  // 바로 이전 상태 (u 빼기)

    // prevMask에 있는 p에서 u로 온다
    int m = prevMask;
    while (m) {
        int p = __builtin_ctz(m);                  // prevMask의 한 도시
        m &= (m - 1);
        if (costMat[p][u] == 0) continue;         // 간선 없으면 스킵 (0도 비용 허용이면 이 줄 제거)
        int prevCost = solveDP(prevMask, p);
        if (prevCost == INF) continue;
        ret = min(ret, prevCost + costMat[p][u]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> costMat[i][j];

    FULL = (1<<n) - 1;
    memset(dp, -1, sizeof(dp));

    // 최종 답: 모두 방문(FULL) 상태에서 어떤 last에 도달한 뒤 start로 복귀
    int ans = INF;
    for (int last = 0; last < n; ++last) {
        int toLast = solveDP(FULL, last);
        if (toLast == INF) continue;
        if (costMat[last][start] == 0) continue;   // 회귀 간선 없음
        ans = min(ans, toLast + costMat[last][start]);
    }

    cout << (ans >= INF ? -1 : ans) << '\n';
    return 0;
}
