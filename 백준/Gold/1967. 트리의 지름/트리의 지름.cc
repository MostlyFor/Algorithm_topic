#include <iostream>
#include <vector>
#include <queue>
using namespace std;



vector<pair<int, int>> adj[10001];
int visit[10001];
int visit2[10001];
int ans = 0;
int dia1 = 0;
int dia2 = 0;
// 해당 노드를 중심으로 했을 때 지름의 최대 길이
void f(int x, int dist) {
	visit[x] = dist;
	dia1 = max(dist, dia1);
	// 인접한 노드 방문하기
	for (auto k : adj[x])
		if(visit[k.first]==0)
			f(k.first, k.second+dist);
}

void f2(int x, int dist) {
	visit2[x] = dist;

	dia2 = max(dist, dia2);
	// 인접한 노드 방문하기
	for (auto k : adj[x])
		// 방문하지 않았다면 방문
		if (visit2[k.first] == 0)
			f2(k.first, k.second + dist);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;

	// 각각의 노드를 방문하면서 왼쪽 오른쪽 재귀로 구현하면 될듯

	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	f(1,1);
	for (int i = 0; i <= n; i++)
		if (visit[i] == dia1)
			dia1 = i;

	f2(dia1, 1);

	cout << dia2-1;

	return 0;
}