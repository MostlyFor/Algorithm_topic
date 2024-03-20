#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[20][20];
int ans = 0;
int dx[4] = { -1,-1,1,1 };
int dy[4] = { 1,-1,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && 0 <= y && x < n&& y < n;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int hx = i; int hy = j;
			int sum = 0;


			for (int dir = 0; dir < 4; dir++) {
				int cnt = 0;
				while (InRange(hx + dx[dir], hy + dy[dir])) {
					sum += board[hx][hy];
					hx += dx[dir];
					hy += dy[dir];
					cnt++;
				}
				if (cnt == 0) sum = -1e9;
			}
			ans = max(ans, sum);
		}
	}


	cout << ans;
	return 0;
}