#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m;
vector<pair<int, int>> adj[101]; // adj[a] = {b,c}: 출발 a, 도착 b, 비용 c


void f(int st) {
	priority_queue<pair<int, int>> pq; // {a, b} a : - 현재까지의 거리 b : 현재 노드 위치 
	vector<int> dist(n + 1, 1e9);
	dist[st] = 0;
	pq.push({ 0, st });

	while (pq.size()) {
		auto k = pq.top(); pq.pop();
		int h = k.second;
		int hcost = -k.first;

		for (auto x : adj[h]) {
			int n = x.first;
			int ncost = x.second;

			if (dist[n] < hcost + ncost) continue;
			dist[n] = hcost + ncost;
			pq.push({ -dist[n], n });
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 1e9) cout << 0 << ' ';
		else cout << dist[i] << ' ';
	}

	cout << '\n';
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	for (int i = 0; i < n; i++) {
		f(i+1);
	}

	return 0;
}