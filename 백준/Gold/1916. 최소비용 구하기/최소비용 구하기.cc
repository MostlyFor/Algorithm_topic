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

priority_queue<pair<int, int>> pq;
vector<pair<int,int>> adj[1001];
int dist[1001] = {};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 1001; i++)
        dist[i] = 2e9;

    // 인접행렬 만들기
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b,c });
    }

    int st, end; cin >> st >> end;

    priority_queue<pair<int, int>> pq; // 목적지까지 걸리는 최소 거리, 목적지
    pq.push({ 0,st });
    dist[st] = 0;
    while (!pq.empty()) {
        int here = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if (dist[here] < d) continue;


        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int step = adj[here][i].second;
            if (dist[next] <= dist[here] + step) continue;
            dist[next] = dist[here] + step;
            pq.push({-dist[here] - step, next});
        }
    }
    
    cout << dist[end];

    return 0;
}