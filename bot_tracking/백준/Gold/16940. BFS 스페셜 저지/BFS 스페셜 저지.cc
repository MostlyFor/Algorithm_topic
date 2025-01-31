#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> adj[100001];
vector<int> arr; // 원하는 배열
vector<int> dist(100001, 0);
vector<int> paidx(100001, 0);
int idx = 0; // 앞으로 확인할 인덱스
void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while (!q.empty()) {
		int h = q.front(); q.pop();

		// 내가 검증하고자 하는 노드가 queue에 들어 있어야함
		for (auto n : adj[h]) {
			if (dist[n] > 0) continue;
			dist[n] = dist[h] + 1;
			q.push(n);
		}
	}
}

int check() {
	if (arr[0] != 1) return 0;

	int idx = 0; // 지워져야 하는 인덱스

	for (int i = 1; i <= n; i++) {
		paidx[i] = adj[i].size() - 1;
	}
	paidx[1]++;

	for (int i = 1; i < n; i++) {
		if (dist[arr[i - 1]] > dist[arr[i]]) return 0; // 단조 증가하지 않는다면
		// 일단 해당 노드에서 부모를 찾기
		int pa;
		for (auto n : adj[arr[i]]) {
			if (dist[arr[i]] > dist[n])
				pa = n;
		}
		if (arr[idx] != pa) return 0;
		paidx[pa]--;
		while (paidx[arr[idx]] == 0) {
			idx++;
			if (idx == n) return 1;
		}
	}

	return 1;
}

int main() {
	input();
	bfs();
	cout << check();
	return 0;
}