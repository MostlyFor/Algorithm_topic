#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[20][20];
int ans = -1;

bool check(int x, int y, int h, int w) {
	bool pos = true;
	for (int i = x; i <= x + h; i++) {
		for (int j = y; j <= y + w; j++) {
			if (board[i][j] <= 0) pos = false;
		}
	}
	return pos;
}


int main() {
	cin >> n >> m;

	// 직사각형의 정의
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int w = 0; j+w < m; w++) {
				for (int h = 0; i + h < n; h++) {
					if (check(i, j, h, w)) {
						ans = max(ans, (h+1) * (w+1));
					}
				}
			}
		}
	}


	cout << ans;
	return 0;
}