#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int map[50][50]; // 빈칸 0 벽 1 청소 2
// 남, 동, 북, 서
int dx[9] = { 1,0,-1,0,1,0,-1,0,1 };
int dy[9] = { 0,1,0,-1,0,1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c; cin >> r >> c;
	int ans = 0;


	int x, y, dir; cin >> x >> y >> dir;
	queue<int> q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		if (map[x][y] == 0) {
			map[x][y] = 2;
			ans++;
		}

		bool find_unclear = false;
		// 주변 칸 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r ||ny >= c) continue;
			if (map[nx][ny] == 0) find_unclear = true;
		}

		if (find_unclear) {
			for (int i = 1; i <= 4; i++) {
				int k = 0;
				if (dir == 0) k = 2;
				else if (dir == 1) k = 1;
				else if (dir == 2) k = 0;
				else if (dir == 3) k = 3;

				int nx = x + dx[i + k];
				int ny = y + dy[i + k];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (map[nx][ny] == 0) {
					x = nx; y = ny;
					if ((i + k) % 4 == 2) dir = 0;
					if ((i + k) % 4 == 1) dir = 1;
					if ((i + k) % 4 == 0) dir = 2;
					if ((i + k) % 4 == 3) dir = 3;
					break;
				}
			}
		}
		
		//2. 주변 4칸이 청소 다 됨-> 2.1) 청소 안한 곳 나올 때 까지 후진
		else if (find_unclear == false) {
			// 청소 안한 곳을 만나거나 벽을 만나면 후진 끝냄
				if (dir == 0) x++;
				else if (dir == 1) y--;
				else if (dir == 2) x--;
				else if (dir == 3) y++;
				if (x < 0 || y < 0 || x >= r || y >= c) {
					cout << ans; return 0;
				}
			// 벽 만나면 끝냄
			if (map[x][y] == 1) {
				cout << ans; return 0;
			}
		}
	}
	return 0;
}