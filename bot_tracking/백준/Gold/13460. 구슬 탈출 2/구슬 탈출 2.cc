#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; // 3 ~ 10
int time = 0;
int ans = 11;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };
vector<string> map;


// 이동 구현
void move(int dir, pair<int,int>& blue, pair<int,int>& red) {

	auto blue_ori = blue; // 빨간색 공을 위한 blue 이전 좌표

	// 파란공 좌표 옮기기
	int hbx = blue.first;
	int hby = blue.second;
	bool check_red = false;
	while (map[hbx][hby] !=  '#') { // 벽
		int nbx = hbx + dx[dir];
		int nby = hby + dy[dir];

		if (map[nbx][nby] == 'O') { // 중간에 흰 구슬 마났다면 종료
			blue.first = -10;
			return;
		}

		if (nbx == red.first && nby == red.second) check_red = true;

		hbx = nbx;
		hby = nby;
	}

	if (check_red) {
		blue.first = hbx - dx[dir] * 2;
		blue.second = hby - dy[dir] * 2;
	}
	else {
		blue.first = hbx - dx[dir];
		blue.second = hby - dy[dir];
	}

	// 빨간공 좌표 옮기기
	int hrx = red.first;
	int hry = red.second;
	bool check_blue = false;
	while (map[hrx][hry] != '#') { // 벽 또는 결승점 또는 다른 벽을 만날 때 까지 접근
		int nrx = hrx + dx[dir];
		int nry = hry + dy[dir];

		if (map[nrx][nry] == 'O') { // 중간에 흰 구슬 마났다면 종료
			red.first = -10;
			return;
		}

		if (nrx == blue_ori.first && nry == blue_ori.second) check_blue = true;
		hrx = nrx;
		hry = nry;
	}

	if (check_blue) {
		red.first = hrx - dx[dir] * 2;
		red.second = hry - dy[dir] * 2;
	}
	else {
		red.first = hrx - dx[dir];
		red.second = hry - dy[dir];
	}

}


void solve(int cnt, pair<int,int> red, pair<int,int> blue) {
	// 만약 10번 넘게 움직였다면 종료
	if (cnt > min(10,ans)) return;

	// 파란 구슬이 빠졌다면 종료
	if (blue.first == -10) return;

	// 빨간 구슬이 빠졌다면 승리
	if (red.first == - 10) {
		ans = min(ans, cnt); return;
	}

	for (int i = 0; i < 4; i++) { // 상하좌우 한번씩 다 해봄
		pair<int, int> blue2 = blue;
		pair<int, int> red2 = red;
		move(i,blue, red); // 공 위치가 바뀜
		solve(cnt + 1, red, blue);
		blue = blue2;
		red = red2;
	}
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}
}

int main() {
	input();
	pair<int, int> blue;
	pair<int, int> red;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'B') {
				blue = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R') {
				red = { i,j };
				map[i][j] = '.';
			}
		}
	}
	solve(0, red, blue);
	if (ans == 11) cout << -1;
	else cout << ans;

	return 0;
}