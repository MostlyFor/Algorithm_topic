#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> p;
int map[500][500]; 
int r, c;

int score(p p1, p p2, p p3, p p4) {
	if (p1.first < 0 || p1.first >= r || p1.second < 0 || p1.second >= c) return -1;
	if (p2.first < 0 || p2.first >= r || p2.second < 0 || p2.second >= c) return -1;
	if (p3.first < 0 || p3.first >= r || p3.second < 0 || p3.second >= c) return -1;
	if (p4.first < 0 || p4.first >= r || p4.second < 0 || p4.second >= c) return -1;

	return map[p1.first][p1.second] + map[p2.first][p2.second] + map[p3.first][p3.second] + map[p4.first][p4.second];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	// 맵 점수 초기화
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	// 테트리스 모양이 정해지면 완전탐색 시작

	// 2. 네모
	// 3. L
	// 4. 번개
	// 5. 방향키

	int ans = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// i, j 를 시작점으로 놓을 수 있는 모양 넣어보기
			// 1. 일자
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 2,j }, { i + 3,j }));
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i,j + 3 }));
			// 2. 네모
			ans = max(ans, score({ i,j }, { i + 1,j }, { i,j + 1 }, { i + 1,j + 1 }));
			// 3. L자
				// 세로형
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 2,j }, { i + 2,j+1 }));
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 2,j }, { i + 2,j - 1 }));

				//가로형
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i+1,j }));
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i-1,j }));

			// 세로형 2
			ans = max(ans, score({ i,j }, { i,j+1 }, { i+1,j+1 }, { i + 2,j + 1 }));
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 2,j }, { i,j+1 }));

			// 가로형 2
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i+1,j +2 }));
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i-1,j + 2 }));

			// 4. 번개
			ans = max(ans, score({ i,j }, { i+1,j}, { i+1,j + 1 }, { i+2,j+1 }));
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 1,j - 1 }, { i + 2,j - 1 }));
			ans = max(ans, score({ i,j }, { i,j+1 }, { i-1,j + 1 }, { i -1,j + 2 }));
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i + 1,j + 1 }, { i + 1,j + 2 }));
			// 5. 방향키
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i+1,j +1 }));
			ans = max(ans, score({ i,j }, { i,j + 1 }, { i,j + 2 }, { i -1,j + 1 }));
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 2,j }, { i + 1,j+1 }));
			ans = max(ans, score({ i,j }, { i + 1,j }, { i + 2,j }, { i + 1,j-1 }));
		}
	}

	cout << ans;

	return 0;
}