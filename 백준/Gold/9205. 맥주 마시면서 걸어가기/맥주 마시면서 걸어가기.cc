#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> con; // 0은 집
int n, x, y;
int gx, gy;
bool visit[101]; // 편의점 + 목적지
void input() {
	con.resize(0);
	cin >> n;
	cin >> x >> y; // 출발지
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		con.push_back({a,b});
	}
	cin >> gx >> gy; // 목적지
	con.push_back({ gx,gy });

	for (int i = 0; i <= n; i++) visit[i] = 0;
}

void bfs() {
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while (q.size()) {
		pair<int,int> h = q.front(); q.pop();

		for (int i = 0; i < n + 1; i++) {
			if (visit[i]) continue;
			int dist = abs(con[i].first - h.first) + abs(con[i].second - h.second);
			if (dist > 1000) continue;
			q.push(con[i]);
			visit[i] = 1;
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		input();
		bfs();
		if (visit[n]) cout << "happy" << '\n';
		else cout << "sad" << '\n';
	}
	return 0;
}