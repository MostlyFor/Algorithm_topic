#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int st, ed; // 출발, 마지막 도시
vector<pair<int, int>> adj[10001];
vector<pair<int, int>> re[10001]; // 역그래프
vector<int> ind(10001, 0);
vector<int> outd(10001, 0);
vector<int> ttn(10001, 0); // 해당 노드까지 가는데 걸리는 최대 시간
vector<int> ttn_re(10001, 0); // 해당 노드까지 역으로 가는데 걸리는 최대 시간
vector<int> visited(10001, 0);
int ans;

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c }); // a에서 출발해서 b로 c 만큼 비용써서 감
		re[b].push_back({ a,c }); // 역그래프
		ind[b]++;
		outd[a]++;
	}

	cin >> st >> ed;
}



void topol() {
	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int h = q.front(); q.pop(); // 현재
		for (auto ne : adj[h]) {
			ind[ne.first]--; // 목표 노드 방문
			ttn[ne.first] = max(ttn[ne.first], ttn[h] + ne.second); // 가장 오래 걸리는 시간
			if (ind[ne.first] == 0) q.push(ne.first);
		}
	}
}

void topol_re() {
	queue<int> q;
	q.push(ed);

	while (!q.empty()) {
		int h = q.front(); q.pop(); // 현재
		for (auto ne : re[h]) {
			outd[ne.first]--; // 목표 노드 방문
			ttn_re[ne.first] = max(ttn_re[ne.first], ttn_re[h] + ne.second); // 가장 오래 걸리는 시간
			if (outd[ne.first] == 0) q.push(ne.first);
		}
	}
}

void erase() {
	// 모든 간선 조사
	for (int i = 0; i < 10001; i++) {
		for (auto edge : adj[i]) {
			if (ttn[i] + ttn_re[edge.first] + edge.second == ttn[ed]) ans++;
		}
	}
}


int main() {
	input();
	topol();
	topol_re();
	cout << ttn[ed] << '\n';
	erase();
	cout << ans;
	return 0;
}