#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int map[300][300];
int T = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

bool split() {
	bool visit[300][300] = { 0, };
	pair<int, int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				visit[i][j] = true;
			}
			else st = { i,j };
		}
	}



	queue<pair<int, int>> q;
	q.push(st);
	visit[st.first][st.second] = 1;

	while (!q.empty()) {
		auto h = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = h.first + dx[i];
			int ny = h.second + dy[i];

			if (visit[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0)
				return true;
		}
	}

	return false;
}

void melt() {
	int map_next[300][300];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int adj = 0;
			for (int dir = 0; dir < 4; dir++) { // 인접한 애들 구하기
				int nx = dx[dir] + i;
				int ny = dy[dir] + j;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] > 0) continue;
				adj++;
			}
			map_next[i][j] = max(0, map[i][j] - adj);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = map_next[i][j];
		}
	}
}

int main() {
	input();
	while (!split()) {
		T++;
		bool no_ = true;
		melt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0)
					no_ = false;
			}
		}
		if (no_) { // 모두 녹은 경우
			cout << 0;
			return 0;
		}
	}

	cout << T;
	return 0;
}