#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x;


// N개의 마을 사람 한 명
// M :도로 단 방향 (오고 가는 시간이 다름)
// X : 마을
// output : 왕복 가장 많은 시간을 소비하는 학생


// 가는 길은 무조건 있음
// 사이클 없고 각 도시마다 가는 거리 하나!
// 갈 때 최단 거리 + 올 때 최단거리 등록

vector<pair<int, int>> adj[1001]; // adj[h] = n, cost
int route1[1001];
int route2[1001];


int dst(int st) {
	vector<int> dist(1001, 1e9);

	priority_queue<pair<int, int>> pq; // 현재까지 오는데 걸린 비용, 현재 위치
	pq.push({ 0, st });
	dist[st] = 0;
	while (pq.size()) {
		auto tmp = pq.top(); pq.pop();
		int h = tmp.second;
		int cost = -tmp.first;

		// 현재 인접한 노드 방문
		for (auto k : adj[h]) {
			int n = k.first;
			int ncost = k.second;

			if (dist[n] < cost + ncost) continue;
			dist[n] = cost + ncost;
			pq.push({ -dist[n], n });
		}
	}

	return dist[x];
}


void dst2(int st) {
	vector<int> dist(1001, 1e9);

	priority_queue<pair<int, int>> pq; // 현재까지 오는데 걸린 비용, 현재 위치
	pq.push({ 0, st });
	dist[st] = 0;
	while (pq.size()) {
		auto tmp = pq.top(); pq.pop();
		int h = tmp.second;
		int cost = -tmp.first;

		// 현재 인접한 노드 방문
		for (auto k : adj[h]) {
			int n = k.first;
			int ncost = k.second;

			if (dist[n] < cost + ncost) continue;
			dist[n] = cost + ncost;
			pq.push({ -dist[n], n });
		}
	}

	for (int i = 1; i <= n; i++)
		route2[i] = dist[i];
}

int main() {

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	
	// 1. 모두의 마을에서 X 번까지의 거리 ..? (다익스트라를 N 번? ..?) N * (M * log N)
	for (int i = 1; i <= n; i++) {
		route1[i] = dst(i);
	}
	
	// 2. X 에서의 거리 (다익스트라 1번)
	dst2(x);


	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, route1[i] + route2[i]);
	}
	cout << ans;
	return 0;
}