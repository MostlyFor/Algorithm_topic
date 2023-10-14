#include <iostream>
#include <vector>

using namespace std;

int n, m, k; // n : 미로의 크기, 참가자 수, 게임 시간
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[10][10]; // 현재 시점 map
vector<int> people; // 사람 좌표
int out_x, out_y; // 출구 좌표
int total_dist; // 최종 거리

// 최상단 (1,1)
// 빈칸, 벽(1~9), 출구 (즉시 탈출)


//참가자 이동
void move() {
	int map_next[10][10] = { 0, }; // 1초 후의 map

	// 2. 모든 참가자 동시
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 사람이 있는 곳
			if (map[i][j] < 0) {

				bool check = false; // 이동했는지 못했는지 확인

				// 이동할 수 있는 네 방향 조사
				for (int dir = 0; dir < 4; dir++) {	// 5. 상하로 움직이는 것 우선
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (map[nx][ny] > 0) continue;	// 3. 벽에 이동 불가
					int now_dist = abs(out_x - i) + abs(out_y - j);	// 1. 최단거리 멘헤튼 
					int next_dist = abs(out_x - nx) + abs(out_y - ny);
					if (now_dist <= next_dist) continue;	// 4. 출구까지의 최단거리가 가까워야 함

					// 모든 조건이 만족하면 이동!
					total_dist += -map[i][j];
					// 만약 이동한 지점이 출구라면 남은 사람 수 줄이고 1초 후의 map에 표시 안함
					if (nx == out_x && ny == out_y) m += map[i][j];
					else map_next[nx][ny] += map[i][j];
					check = true;
					break;
				}

				//이동 못했다면 다음 시간데에 포함
				if (!check)
					map_next[i][j] += map[i][j];
			}
		}
	}

	// 1초 후의 map 동기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < 0) map[i][j] = 0;
			if (map_next[i][j] < 0) map[i][j] = map_next[i][j];
		}
	}
}

void rotate(int x, int y, int l) {
	vector<vector<int>> map_rotate(l + 1, vector<int>(l + 1, 0));


	// map_rotate에 map 복사
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			map_rotate[i][j] = map[x + i][y + j];
		}
	}

	// map_rotate에 출구 좌표 표시
	map_rotate[out_x - x][out_y - y] = 100;

	// 시계방향 90도 회전 
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			map[x + i][y + j] = map_rotate[l - j][i];
			// 만약 출구라면 출구 좌표 수정
			if (map[x + i][y + j] == 100) {
				out_x = x + i; out_y = y + j;
				map[x + i][y + j] = 0;
			}
			// 회전할 때 내구도 감소
			if (map[x + i][y + j] > 0) map[x + i][y + j]--;
		}
	}
}


// 참가자 이동 후 미로 회전
// 1. 한 명 이상의 참가자와 출구를 포함한 정사각형
// 2. 정사각형은 r 좌표가 작은 것이 우선순위가 됨
// 3. 정사각형 회전
void find_sq() {
	// 정사각형 찾기
	// 1. 가장 길이가 작은 정사각형 찾기
	int length = 9;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 만약 사람이라면 
			if (map[i][j] < 0) {
				length = min(length, max(abs(out_x - i), abs(out_y - j)));
			}
		}
	}

	// 2. 해당 길이 정사각형으로 잘랐을 때 조건에 맞는지 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 출구가 포함되어 있는지 확인
			if (i + length >= n || j + length >= n) continue;
			if (i <= out_x && j <= out_y && out_x <= i + length && out_y <= j + length) {
				// 사람이 포함되어 있는지 확인,, 이때 시간이 엄청 늘어질 수도 있음 
				for (int x = i; x <= i + length; x++) {
					for (int y = j; y <= j + length; y++) {
						// 사람이 포함되어 있다면 90도 회전
						if (map[x][y] < 0) {
							rotate(i, j, length);
							return;
						}
					}
				}
			}
		}
	}
}


int main() {

	cin >> n >> m >> k;

	// 맵 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// 사람 위치 좌표 받기, 사람 : - 10
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		map[a][b] += -1;
	}

	// 출구 좌표 받기
	cin >> out_x >> out_y;
	out_x--; out_y--;


	// k초
	while (k--) {
		//참가자 움직임
		move();

		// 이동 끝난 후 K초 동안 총 이동거리와 출구 좌표, 물론 참가자 없으면 바로종료함
		if (m == 0) break;

		// 참가자 이동 후 정사각형 찾고 미로 회전
		find_sq();
	}


	cout << total_dist << '\n' << out_x + 1 << ' ' << out_y + 1;

	return 0;
}