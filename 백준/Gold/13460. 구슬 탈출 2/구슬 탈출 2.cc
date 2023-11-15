#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; // 3 ~ 10
int time = 0;
int ans = 11;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };

// 이동 구현
vector<string> move(int dir, vector<string> map) {
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

	// 파란공 좌표 옮기기
	int hbx = blue.first;
	int hby = blue.second;
	bool check_red = false;
	while (map[hbx][hby] !=  '#') { // 벽
		int nbx = hbx + dx[dir];
		int nby = hby + dy[dir];

		if (map[nbx][nby] == 'O') { // 중간에 흰 구슬 마났다면 종료
			return vector<string>(0, "");
		}

		if (nbx == red.first && nby == red.second) check_red = true;

		hbx = nbx;
		hby = nby;
	}

	if (check_red) map[hbx - dx[dir] * 2][hby - dy[dir] * 2] = 'B';
	else map[hbx - dx[dir]][hby - dy[dir]] = 'B';

	// 빨간공 좌표 옮기기
	int hrx = red.first;
	int hry = red.second;
	bool check_blue = false;
	while (map[hrx][hry] != '#') { // 벽 또는 결승점 또는 다른 벽을 만날 때 까지 접근
		int nrx = hrx + dx[dir];
		int nry = hry + dy[dir];

		if (map[nrx][nry] == 'O') { // 중간에 흰 구슬 마났다면 종료
			return vector<string>(1, "");
		}

		if (nrx == blue.first && nry == blue.second) check_blue = true;
		hrx = nrx;
		hry = nry;
	}

	if (check_blue) map[hrx - dx[dir] * 2][hry - dy[dir] * 2] = 'R';
	else map[hrx - dx[dir]][hry - dy[dir]] = 'R';

	return map;
}


void solve(int cnt, vector<string> map) { 
	// 만약 10번 넘게 움직였거나 이동과정에서 파란 구슬이 빠졌다면 종료
	if (cnt > min(10,ans) || map.size() == 0) return;

	// 빨간 구슬이 빠졌다면 승리
	if (map.size() == 1) {
		ans = min(ans, cnt); return;
	}

	for (int i = 0; i < 4; i++) { // 상하좌우 한번씩 다 해봄
		vector<string> map2 = move(i, map);
		solve(cnt + 1, map2);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> map;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}

	solve(0, map);

	if (ans == 11) cout << -1;
	else cout << ans;

	return 0;
}