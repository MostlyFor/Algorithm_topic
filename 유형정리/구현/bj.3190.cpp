#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int map[100][100]; // 뱀 머리 1 뱀 몸 2 사과 4
int dx[4] = {0,1,0,-1};
int dy[4] = { 1,0,-1,0 };
int time = 1;
int dir;
int head;

queue<int> pos;

int main() {
	int k;
	cin >> n >> k;
	// 사과 정보 표기
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		map[x][y] = 4;
	}
	map[0][0] = 1;
	pos.push(0);

	int L; cin >> L; // 방향전환 타임

	int L_last = L;

	while (L-- >= 0) {
		int ch_time; 
		char dir_c;
		int ch_dir = 0;
		if (L == -1) {
			ch_time = 200;
			ch_dir = 1;
		}
		else {
			cin >> ch_time;
			cin >> dir_c;

			if (dir_c == 'D') ch_dir = 1;
			else if (dir_c == 'L') ch_dir = 3;
		}
		// 방향 전환 타임 때 까지 이동!
		while (time <= ch_time) {
			// 현재의 뱀 머리의 위치 파악
			int hx = head / 1000;
			int hy = head % 1000;

			// 앞으로 뱀이 갈 방향
			int nx = hx + dx[dir];
			int ny = hy + dy[dir];

			// 만약 벽이나 자기 자신의 몸이라면
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				cout << time; return 0;
			}
			if (map[nx][ny] == 2) {
				cout << time; return 0;
			}

			
			// 만약 칸에 사과 있다면 꼬리 안움직임
			if (map[nx][ny] == 4) {
				map[nx][ny] = 1;
				head = 1000 * nx + ny;
				map[hx][hy] = 2;
				pos.push(nx * 1000 + ny);
			}

			// 만약에 칸에 사과 없다면 꼬리 안움직임
			else if (map[nx][ny] != 4) {
				map[nx][ny] = 1;
				head = 1000 * nx + ny;
				map[hx][hy] = 2;
				pos.push(head);
				// 꼬리 부분 제거
				int tail = pos.front(); pos.pop();
				int tx = tail / 1000;
				int ty = tail % 1000;
				map[tx][ty] = 0;
			}
			time++;
		}

		// 방향 전환 타임이 되면 방향 이동
		dir += ch_dir;
		dir %= 4;

 	}

	cout << time;

	return 0;
}
