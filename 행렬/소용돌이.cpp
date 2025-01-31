#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1}; // 우 하 좌 상
int dy[4] = { 1,0,-1,0 };

int map[5][5];
int main() {
	int cnt = 25;
	int n = 5;
	int d = 0;
	int hx = 0;
	int hy = 0;
	while(cnt--){
		map[hx][hy] = cnt;
		int nx = hx + dx[d];
		int ny = hy + dy[d];
		// 만약 겹치면 방향 바꾸기
		if ((nx < 0 || ny < 0 || nx >= n || ny >= n) || map[nx][ny]!=0) {
			d = (d + 1) % 4;
			nx = hx + dx[d];
			ny = hy + dy[d];
		}

		hx = nx;
		hy = ny;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}