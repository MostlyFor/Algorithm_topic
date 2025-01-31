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


vector<pair<int,int>> adj[100001];
int st, ed;

bool bfs(int k) {

    queue<int> q;
    q.push(st);
    bool visit[100001] = { 0, };
    while (!q.empty()) {
        int h = q.front(); q.pop();

        for (int i = 0; i < adj[h].size(); i++) {
            int n = adj[h][i].first;
            int w = adj[h][i].second;
            if (w < k) continue;
            if (visit[n]) continue;
            if (n == ed) return true;
            visit[n] = true;
            q.push(n);
        }
    }

    return false;
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    cin >> st >> ed;

    int l = 0;
    int r = 1e9;

    while (l <= r) {
        int mid = (l + r)/2;
        if (bfs(mid)) l = mid + 1;
        else r = mid - 1;
    }
    
    cout << r;
    
    return 0;
}