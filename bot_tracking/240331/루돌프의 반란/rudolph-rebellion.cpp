#include <iostream>
#include <vector>

using namespace std;

int n, m, p, c, d; // n : 맵, m : 게임 턴, p : 산타 수, c : 루돌프 힘, d : 산타 힘
int board[50][50]; // 루돌프 -1, 산타 번호 p
int score[31]; // 산타 점수
int cooltime[31]; // 산타가 움직일 수 있는 시간 , out : 1e9
int turn = 0; // 시간


int dx[8] = { -1,0,1,0,-1, - 1,1,1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };



void input() {
	cin >> n >> m >> p >> c >> d;

	// 루돌프의 위치
	{
		int a, b; cin >> a >> b;
		board[a - 1][b - 1] = -1;
	}

	// 산타의 번호와 초기 위치
	for (int i = 0; i < p; i++) {
		int a, b, c; cin >> a >> b >> c;
		board[b - 1][c - 1] = a;
	}

}


int get_dist(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool InRange(int x, int y) {
	return 0 <= x && 0 <= y && x < n&& y < n;
}



// 상호작용 (x,y에 착지, santa_idx : 현재 날라가고 있는 산타)
void interaction(int x, int y, int santa_idx, int dir) {
	if (!InRange(x, y)) {
		return;
	}

	// 해당 칸에 산타가 없다면 값 넣고 종료
	if (!(board[x][y] > 0)) {
		board[x][y] = santa_idx; return;
	}
	
	// 산타가 있다면
	int next_santa_idx = board[x][y];
	board[x][y] = santa_idx;
	interaction(x + dx[dir], y + dy[dir], next_santa_idx, dir);
}



// 1. 루돌프 움직임
// 탈락하지 않은 가장 가까운 산타 (r좌표가 큰 산타, c 좌표도 고려)
// 인접한 8방향 1칸
void move_r() {

	// 1. 루돌프 움직이기
	// 1-1. 루돌프 좌표 구하기
	pair<int, int> ru;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (board[i][j] == -1) ru = { i,j };
	// 1-2. 우선순위 생각한 가장 가까운 산타 구하기
	pair<int, int> sa;

	int min_dist = 1e9;
	for (int i = n-1; i >= 0; --i) {
		for (int j = n-1; j>= 0; --j) {
			if (board[i][j] <= 0) continue;
			int dist = get_dist(i, j, ru.first, ru.second);

			// 거리 갱신
			if (min_dist > dist) {
				sa = { i,j };
				min_dist = dist;
			}
		}
	}

	// 1-3. 루돌프 산타와 가장 가까워 지는 방향 찾기
	int direction = -1;

	// 루돌프 이동 방향
	for (int dir = 0; dir < 8; dir++) {
		int hx = ru.first;
		int hy = ru.second;

		int nx = hx + dx[dir];
		int ny = hy + dy[dir];

		if (!InRange(nx, ny)) continue;
		int new_dist = get_dist(nx, ny, sa.first, sa.second);
		if (new_dist < min_dist) {
			min_dist = new_dist;
			direction = dir;
		}
	}

	// 1-4 방향 찾았으니 해당 칸으로 이동
	int nx = ru.first + dx[direction];
	int ny = ru.second + dy[direction];
	board[ru.first][ru.second] = 0;


	// 1-5 충동 발생 x
	if (board[nx][ny] == 0) {
		board[nx][ny] = -1; return;
	}

	// 1-6 충돌 발생 o : 산타는 점수 C 얻고 루돌프 방향만큼 C 만큼 밀려남
	int santa_idx = board[nx][ny];
	cooltime[santa_idx] = turn + 1;
	board[nx][ny] = -1;
	score[santa_idx] += c;

	// 산타가 밀려나게 되는 곳
	int santa_nx = nx + c * dx[direction];
	int santa_ny = ny + c * dy[direction];


	// 1-7 산타 위치 갱신
	// 범위 밀려나면 산타 아웃 -> board에서 사라짐
	if (!InRange(santa_nx, santa_ny)) {
		cooltime[santa_idx] = 1e9;
		return;
	}

	// 1-8 그 곳이 빈 경우
	if (board[santa_nx][santa_ny] == 0) {
		board[santa_nx][santa_ny] = santa_idx;
		return;
	}

	// 1-8 그 곳에 산타 존재
	interaction(santa_nx, santa_ny, santa_idx, direction);
}



// 2. 산타 움직임
void move_s() {
	// 1. 산타 이동 
	// 1-1. 산타 위치와 번호, 루돌프 위치 갱신)
	pair<int, int> santa_pos[31];
	pair<int, int> ru;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0) santa_pos[board[i][j]] = { i,j };
			else if (board[i][j] == -1) ru = { i,j };
		}
	}

	// 1-2. 산타 번호순으로 이동 (i : 산타 번호)
	for (int i = 1; i <= p; i++) {
		// 아웃이거나 기절이면 이동 x
		if (cooltime[i] >= turn) continue;
		int hx = santa_pos[i].first;
		int hy = santa_pos[i].second;
		// 현재 루돌프와의 거리
		int dist = get_dist(hx,hy,ru.first, ru.second);
		int direction = -1;

		// 루돌프에게 거리가 가장 가까워지는 방향으로 이동
		for (int dir = 0; dir < 4; dir++) {
			int nx = hx + dx[dir];
			int ny = hy + dy[dir];

			if (!InRange(nx, ny)) continue;
			if (board[nx][ny] > 0) continue;
			int new_dist = get_dist(nx, ny, ru.first, ru.second);

			// 최단거리 갱신
			if (dist > new_dist) {
				dist = new_dist;
				direction = dir;
			}
		}

		// 최단거리 구했으니 해당 방향으로 이동
		int nx = hx + dx[direction];
		int ny = hy + dy[direction];

		if (board[nx][ny] != -1) {
			board[hx][hy] = 0;
			board[nx][ny] = i;
		}
		// 2. 만약 이동하려는 칸에 루돌프가 있다면?
		// 산타 -> 루돌프 (기절)
		else if (board[nx][ny] == -1) {
			cooltime[i] = turn + 1;
			score[i] += d;
			int santa_nx = nx - d * dx[direction];
			int santa_ny = ny - d * dy[direction];
			board[hx][hy] = 0;
			if (!InRange(santa_nx, santa_ny)) {
				cooltime[i] = 1e9;
			}
			else {
				// 산타와 충돌하는 경우
				interaction(santa_nx, santa_ny, i, (direction + 2) % 4);
			}
		}
	}
}

// 각 산타가 얻은 최종 점수
void output() {
	for (int i = 1; i <= p; i++)
		cout << score[i] << ' ';
}


int main() {

	input();

	while (turn < m) {

		turn++;

		// 루돌프 움직임



		move_r();

		// 산타 움직임
		move_s();

		int santa = 0;
		// 매 턴마다 탈락하지 않은 산타 + 1점 추가
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > 0) {
					score[board[i][j]]++;
					santa++;
				}
			}
		}
		// 만약 산타가 모두 탈락했다면 게임 종료
		if (santa == 0) break;
	}



	output();
	return 0;
}