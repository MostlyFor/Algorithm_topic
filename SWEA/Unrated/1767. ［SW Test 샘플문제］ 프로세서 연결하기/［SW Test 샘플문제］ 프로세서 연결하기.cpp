#include <iostream>
#include <vector>
using namespace std;
int T;
int turn;
int dx[5] = { 0,1,0,-1, 100 };
int dy[5] = { 1,0,-1,0, 100};


// 턴마다 초기화
int n;
int board[12][12]; // 1이면 core, 2면 선
vector<pair<int, int>> arr; // 충전해야할 core 위치
int number;
int total_length;
int best_hit;



void input() {
	cin >> n;
	arr.clear();
	total_length = 0;
	best_hit = 0;



	// board, arr, number 세팅
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			

			// 코어
			if (board[i][j] == 1) {
				// 이미 충전된 코어
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
					continue;
				}
				else {
					arr.push_back({ i,j });
				}
			}
		}
	}


}

bool is_out(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}

// idx 번째 충전 코어를 이 함수에서 채움
void f(int idx, int hit, int length) {
	
	if (hit + arr.size() - idx < best_hit) return;

	// 모든 코어 다 충전함
	if (idx == arr.size()) {
		if (hit > best_hit) {
			best_hit = hit;
			total_length = length;

		}
		else if (hit == best_hit) {
			if (total_length > length) total_length = length;
		}
		return;
	}


	// 동서남북 + 선택 안함
	for (int dir = 0; dir < 4; dir++) {

		bool is_pos = false;
		vector<pair<int, int>> tmp; // 해당 함수에서 깔린 선 수
		int x = arr[idx].first;
		int y = arr[idx].second;


		// 장애물을 만날 때 까지 해당 방향으로 이동 (x,y 는 멈추기 이전 좌표)
		while (1) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (is_out(nx,ny)) break; // 밖에 나가는 경우
			if (board[nx][ny] != 0) break; //뭔가가 있는 경우
			
			x = nx;
			y = ny;
			board[nx][ny] = 2;
			tmp.push_back({ nx,ny });
		}

		// 선이 연결된 경우
		if (x == 0 || y == 0 || x == n - 1 || y == n - 1) {
			f(idx + 1, hit + 1, length + tmp.size());
		}

		// 다음 경우를 위해 board에서 선 해제
		for (auto h : tmp) {
			board[h.first][h.second] = 0;
		}
	}

	// 선택 안함 경우의 수
	f(idx + 1, hit, length);
}


int main() {
	cin >> T;
	while (T--) {
		turn++;
		input();
		f(0, 0, 0);
		cout << '#' << turn << ' ' << total_length << '\n';
	}

	return 0;
}