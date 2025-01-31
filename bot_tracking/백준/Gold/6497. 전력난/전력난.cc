#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int parent[200000];
int level[200000];

// 최소 길이 간선을 위한 pq
priority_queue<pair<int, pair<int, int>>> pq;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (level[a] < level[b]) swap(a, b);

	parent[b] = a;

	if (level[a] == level[b]) level[a]++;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int n, m; cin >> n >> m;
		if (n == 0) return 0;
		int total_cost = 0;
		for (int i = 0; i < m; i++) {
			level[i] = 1;
			parent[i] = i;
			int a, b, c; cin >> a >> b >> c;
			total_cost += c;
			pq.push({ -c, { a,b } });
		}

		while (pq.size()) {
			int h = pq.top().second.first;
			int n = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();

			// 만약 h와 n이 같은 집합이면 pss
			h = find(h);
			n = find(n);
			if (h == n) continue;
			// 다른 집합이면 merge
			merge(h, n);
			total_cost -= cost;
		}
		cout << total_cost << '\n';
	}

	return 0;
}