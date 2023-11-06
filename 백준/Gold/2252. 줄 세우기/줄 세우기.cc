#include<iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[32001]; // 연결 그래프
vector<int> county(32001, 0); // 진입차수
int n, m; // n : 노드 수
vector<int> ans;


void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
		county[a]++;
	}
}

void solve() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (county[i] == 0) q.push(i);
	}

	while (q.size()) {
			int h = q.front(); q.pop();
			ans.push_back(h);
			for (auto ne : adj[h]) {
				county[ne]--;
				if (county[ne] == 0) q.push(ne);
			}
	}
}

void output() { for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' '; }

int main() {
	input();
	solve();
	output();
	return 0;
}