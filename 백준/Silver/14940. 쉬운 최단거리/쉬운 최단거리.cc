#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int board[1000][1000];
int dist[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

bool InRange(int x, int y) {
	return 0 <= x && 0 <= y && x < n && y < m;
}

int stx, sty;
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {

		cin >> board[i][j];
		if (board[i][j] == 2) {
			stx = i;
			sty = j;
		}
	}

	queue<pair<int, int>> q;

	q.push({ stx,sty });

	while (q.size()) {
		auto h = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = h.first + dx[i];
			int ny = h.second + dy[i];

			if (!InRange(nx, ny)) continue;
			if (board[nx][ny] != 1) continue;
			if (dist[nx][ny]) continue;
			dist[nx][ny] = dist[h.first][h.second] + 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && dist[i][j] == 0) cout << -1 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}