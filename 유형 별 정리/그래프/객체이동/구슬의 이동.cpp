#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m ,t ,k;
int dx[4] = { -1,0,1,0};
int dy[4] = { 0,1,0,-1};
// 구슬의 특성 = 구슬의 번호, 구슬의 속도, 구슬의 방향
vector<int> balls[2500];

int main() {
	// 입력 받기
	cin >> n >> m >> t >> k;

	for(int i=0;i <m; i++){
		int x, y; cin >> x >> y; x--; y--; // -1 보정
		char dir_ch; cin >> dir_ch;
		int dir = -1;
		if (dir_ch == 'U') dir = 0;
		if (dir_ch == 'R') dir = 1;
		if (dir_ch == 'D') dir = 2;
		if (dir_ch == 'L') dir = 3;
		int v; cin >> v;
		balls[i].push_back(x * 100 + y);
		balls[i].push_back(dir);
		balls[i].push_back(v);
	}

	// 시간마다 구슬 이동
	while (t--) {
		// 다음 타임스탭에 구슬의 개수
		int map[50][50] = {0,};

		// 구슬 각각 t+1 위치에 어디에 있는지 계산
		for (int i = 0; i < m; i++) {
			if (balls[i][0] < 0) continue;
			int x = balls[i][0] / 100;
			int y = balls[i][0] % 100;
			int dir = balls[i][1];
			int v = balls[i][2];

			int nx = x; int ny = y;
			// 이후 좌표 갱신, 이 부분만 잘 하면 됨
			while (v--) {
				nx = nx + dx[dir];
				ny = ny + dy[dir];
				// 나갔으면 한칸 전으로
				if (0 > nx || 0 > ny || nx >= n || ny >= n) {
					dir += 2; dir %= 4;
					nx = nx + dx[dir] *2;
					ny = ny + dy[dir] * 2;
				}
			}

			// t+1 타임에서의 구슬의 특성 저장
			balls[i][0] = 100 * nx + ny;
			balls[i][1] = dir;

			// 새로운 위치를 map에 갱신
			map[nx][ny]++;
		}


		// 만약 해당 좌표의 구슬의 개수가 k 보다 크다면 제거
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > k) {
					// i, j를 가지는 구슬 점검 (이 부분이 좀 비효율적일 수도 있다)
					// 1. 속도 우선순위를 본다., 2순위로 번호 우선순위를 본다
					vector<pair<int, int>> vel_num;
					for (int ball = 0; ball <m; ball++) {
						// 구슬이 이미 제거되어 해당 번호에 존재하지 않으면 pass
						if (balls[ball][0] == -1) continue;

						// 구슬이 존재하면 예비 번호 부여
						if (balls[ball][0] == 100 * i + j) 
							vel_num.push_back({ -balls[ball][2], -ball });
					}

					sort(vel_num.begin(), vel_num.end());
					// 구슬 제거
					for (int ball = k; ball < vel_num.size(); ball++) {
						// 구슬 제거 후 -1
						balls[-vel_num[ball].second][0] = -1;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (balls[i][0] >= 0) ans ++;
	}
	cout << ans;


	return 0;
}