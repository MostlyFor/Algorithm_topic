#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int n ,m ,k; // n :  맵크기, M : 참가자 수, K : 게임 시간


int board[10][10]; // 빈 칸 - 0, 벽(내구도) - 0 ~ 9, 출구 , 참가자 여러 명 가능 
vector<pair<int, int>> pos;
pair<int, int> end_point;
int total_move = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };



void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		pos.push_back({ a-1,b-1 });
	}


	int a, b; cin >> a >> b;
	end_point = { a-1,b-1 };
}


void init() {

}

bool InRange(int x, int y) {
	return 0 <= x && 0 <= y && x < n && y < n;
}

void check_pos() {
}


// 움직임 조건
// 1. 모든 참가자 동시
// 2. 움직인 칸은 출구와 가까워져야함
// 3. 움직일 수 있는 칸이 2칸 이상이면 상,하로 움직이는 것 우선시
// 4. 움직일 수 없으면 안움직임
// 5. 한 칸에 2명 이상 참가자 가능

void move() {
	// 각자 최단거리 방향으로 갈 수 있는지?
	// 1. pos 사람들 이동 후 pos 갱신 및 탈출한 사람 없애기
	for (int i = 0; i < pos.size(); i++) {
		auto p = pos[i];
		int hx = p.first;
		int hy = p.second;
		int dist = abs(hx - end_point.first) + abs(hy - end_point.second);
		for (int dir = 0; dir < 4; dir++) {
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];
			if(!InRange(nx,ny)) continue; // 범위
			if (1 <= board[nx][ny]) continue; // 벽
			int new_dist = abs(nx - end_point.first) + abs(ny - end_point.second);
			if (new_dist >= dist) continue; // 최단거리 아닌 경우
			
			pos[i] = { nx, ny };
			total_move++;
			break;
		}
	}

	// 2. 미로 탈출한 사람 pos에서 없애기
	vector<pair<int, int>> new_pos;

	for (int i = 0; i < pos.size(); i++) {
		if (pos[i] == end_point) continue;
		new_pos.push_back(pos[i]);
	}

	pos.clear();
	pos = new_pos;
}



void rotate_90(int x, int y, int length) {

	// 벽 돌리기
	vector<vector<int>> tmp(length, vector<int>(length, 0));
	vector<vector<int>> tmp_next(length, vector<int>(length, 0));

	// 원래 벽 정보 복사
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			tmp[i][j] = board[i+x][j+y];
		}
	}

	// tmp_next에 회전된 벽 정보 저장
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			tmp_next[j][length - (i + 1)] = tmp[i][j];
		}
	}

	// 벽 정보 갱신
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			board[i+x][j+y] = max(tmp_next[i][j]-1,0);
		}
	}

	// 사람과 end_point 돌리기
	// 범위 안에 있는 사람
	for (int lll = 0; lll < pos.size(); lll++) {
		auto p = pos[lll];
		if (x <= p.first && p.first < x + length && y <= p.second && p.second < y + length) {
			// p : x + i, y + j
			int i = p.first - x;
			int j = p.second - y;

			// (i, j) -> 
			int new_i = j;
			int new_j = length - (i + 1);

			// 
			pos[lll] = { new_i+x, new_j+y };
		}
	}

	// end point 변환
	int i = end_point.first - x;
	int j = end_point.second - y;

	// (i, j) -> 
	int new_i = j;
	int new_j = length - (i + 1);

	// 
	end_point.first = new_i + x;
	end_point.second = new_j + y;
}

bool is_possible(int x, int y, int length) {

	// 정사각형이 범위 나가는지 확인
	if (!InRange(x + length-1, y + length-1)) return false;

	// 해당 정사각형 안에 사람이랑 출구 모두 있는지
	bool is_in_p = false;
	bool is_in_end = false;

	for (auto p : pos) {
		if (x <= p.first && p.first < x + length && y <= p.second && p.second < y + length) is_in_p = true;
	}

	if (x <= end_point.first && end_point.first < x + length && y <= end_point.second && end_point.second < y + length) is_in_end = true;

	return is_in_p && is_in_end;
}

// 미로 회전 - 회전하면 벽 내구도 1 깎임
void rotate() {

	// 1. 회전 범위 구하기 (정사각형 이어야 함 !!)
	int x = -1, y = -1, len = -1;

	for (int qq = 2; qq <= n; qq++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (x != -1) break;
				if (is_possible(i, j, qq)) {
					x = i; y = j; len = qq;
				}
			}
		}
	}


	// 2. 회전
	rotate_90(x,y,len);

}

// 모든 참가자들의 이동거리 합, 출구 좌표
void output() {
	cout << total_move << '\n';
	cout << end_point.first+1 << ' ' << end_point.second+1;
}

int main() {
	input();

	while (k--) {
		init();

		move(); 

		// 만약 모든 참가자 탈출
		if (pos.size() == 0) break;

		rotate();
	}

	output();

	return 0;
}