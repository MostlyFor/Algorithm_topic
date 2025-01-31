#include <iostream>
#include <queue>
using namespace std;

int T = 1;
int turn;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int K; // 턴 수 
int M; // 유물 조각의 개수
queue<int> arr; // 유물 조각 모음
int board[5][5];
int board_ori[3][3];
int board_cp[3][3];
int answer = 0; // 해당 턴에 획득한 유물 수



void input() {
	arr = queue<int>();
	cin >> K >> M;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		arr.push(a);
	}

}

void test_board_ori() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board_ori[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}


void test_board_cp() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board_cp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void test_board() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void rotate(int x, int y, int dir) {

	
	int board_tmp[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board_tmp[i][j] = 0;
			board_cp[i][j] = board[x + i][y + j];
		}
	}


	while (dir--) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board_tmp[j][2 - i] = board_cp[i][j];
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board_cp[i][j] = board_tmp[i][j];
			}
		}
	}
}


int bfs() {

	int score = 0;

	int visited[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visited[i][j]) continue;
			vector<pair<int, int>> tmp;
			queue <pair<int, int>> q;
			q.push({ i,j });
			tmp.push_back({ i,j });
			visited[i][j] = 1;


			
			while (q.size()) {
				auto h = q.front(); q.pop();
				int hx = h.first;
				int hy = h.second;

				for (int dir = 0; dir < 4; dir++) {
					int nx = hx + dx[dir];
					int ny = hy + dy[dir];

					if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
					if (visited[nx][ny]) continue;
					if (board[hx][hy] != board[nx][ny]) continue;
					q.push({ nx,ny });
					visited[nx][ny] = 1;
					tmp.push_back({ nx,ny });
				}
			}

			int tt = tmp.size();
			if (tt < 3) continue;
			score += tt;
			
		}
	}

	return score;
	
}

void bfs_remove() {
	int visited[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visited[i][j]) continue;
			vector<pair<int, int>> tmp;
			queue <pair<int, int>> q;
			q.push({ i,j });
			tmp.push_back({ i,j });
			visited[i][j] = 1;



			while (q.size()) {
				auto h = q.front(); q.pop();
				int hx = h.first;
				int hy = h.second;

				for (int dir = 0; dir < 4; dir++) {
					int nx = hx + dx[dir];
					int ny = hy + dy[dir];

					if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
					if (visited[nx][ny]) continue;
					if (board[hx][hy] != board[nx][ny]) continue;
					q.push({ nx,ny });
					visited[nx][ny] = 1;
					tmp.push_back({ nx,ny });
				}
			}


			if (tmp.size() >= 3) {
				for (auto xx : tmp) board[xx.first][xx.second] = 0;
			}
		}
	}
}

int bfs_inter() {
	int score = 0;

	int visited[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visited[i][j]) continue;
			vector<pair<int, int>> tmp;
			queue <pair<int, int>> q;
			q.push({ i,j });
			tmp.push_back({ i,j });
			visited[i][j] = 1;



			while (q.size()) {
				auto h = q.front(); q.pop();
				int hx = h.first;
				int hy = h.second;

				for (int dir = 0; dir < 4; dir++) {
					int nx = hx + dx[dir];
					int ny = hy + dy[dir];

					if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
					if (visited[nx][ny]) continue;
					if (board[hx][hy] != board[nx][ny]) continue;
					q.push({ nx,ny });
					visited[nx][ny] = 1;
					tmp.push_back({ nx,ny });
				}
			}


			if (tmp.size() >= 3) {
				score += tmp.size();
				for (auto xx : tmp) board[xx.first][xx.second] = 0;
			}
		}
	}

	return score;
}

// 1. 탐사 진행
void find_move() {

	int best_score = -1; // 우선순위 1 유물 획득 가치
	int best_dir = 10; //우선순위 2 적은 회전 수
	int best_i = -1, best_j = -1;

	// 우선순위 3 회전 중심 좌표 열이 작은 구간, 행이 작은 구간
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			for (int dir = 1; dir <= 3; dir++) {


				// test_board();

				// 0. 원본 저장
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						board_ori[x][y] = board[i + x][j + y];
					}
				}
				

				// 1. 회전 후 board 동기화
				rotate(i, j, dir);

				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						board[x + i][y + j] = board_cp[x][y];
					}
				}

				// 해당 상태에서 bfs로 점수 판별하기
				int score = bfs();

				if (best_score < score) {
					best_score = score;
					best_dir = dir;
					best_i = i;
					best_j = j;
				}

				else if (best_score == score) {
					if (best_dir > dir) {
						best_i = i;
						best_j = j;
						best_dir = dir;
					}
				}


				// 3. 다시 board 동기화
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						board[i + x][j + y] = board_ori[x][y];
					}
				}
			}
		}
	}


	// 해당 정보를 이용해서 회전 후 제거
	answer += best_score;
	rotate(best_i, best_j, best_dir);

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			board[x + best_i][y + best_j] = board_cp[x][y];
		}
	}

	// 여기서 bfs()를 한번 더 진행하여 제거
	 bfs_remove();

	 // 빈칸 채우기
	 for (int j = 0; j < 5; j++) {
		 for (int i = 4; i >= 0; i--) {
			 if (board[i][j] == 0) {
				 board[i][j] = arr.front(); arr.pop();
			 }
		 }
	 }
}



void interaction() {

	int score = 0;

	// 연쇄 반응
	while (1) {
		int score = bfs_inter();
		if (score == 0) break;
		answer += score;

		// 빈칸 채우기
		for (int j = 0; j < 5; j++) {
			for (int i = 4; i >= 0; i--) {
				if (board[i][j] == 0) {
					board[i][j] = arr.front(); arr.pop();
				}
			}
		}
	}
}

int main() {
	while (T--) {
		input();
		while (turn < K) {
			turn++;
			answer = 0;

			// 1. 탐사 진행 (우선은 겹치는거 다 제거하고 새로 채워넣는 것)
			find_move();

			// 2. 연쇄반응 (채워진 이후 다시 겹치는 거 있는지 찾고 무한 채워넣기)
			interaction();


			// output : 각 턴마다 획득한 유물의 가치 총 합
            if(answer ==0) return 0;
			cout << answer << ' ';
		}
	}

	return 0;
}