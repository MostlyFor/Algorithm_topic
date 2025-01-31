#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;


vector<pair<int, int>> adj[1001];
int dist[1001];
long long dp[1001];
int ans;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b,c, });
        adj[b].push_back({ a,c });
    }

    for (int i = 0; i < 1001; i++) dist[i] = 2e9;

    priority_queue<pair<int, int>> pq; // 목적지까지의 최소거리, 목적지
    pq.push({ 0,2 });
    dist[2] = 0;
    dp[2] = 1;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (cost > dist[here]) continue;

        // 갈 수 있는 곳 조사
        for (auto k : adj[here]) {
            int next = k.first;
            int step = k.second;

            if (dist[next] > cost + step) {
                dist[next] = cost + step;
                pq.push({ -dist[next], next });
            }

            if (dist[next] > dist[here]) {
                dp[next] += dp[here];
            }

        }
    }

    cout << dp[1];

    return 0;
}