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
			int tt1 = i, tt2 = j;
			for (int dir1 = 1; dir1 < n; dir1++) {
				hx = tt1; hy = tt2;
				int sum1 = 0;
				int tmp1 = dir1;
				while (tmp1) {
					if (!InRange(hx + dx[0], hy + dy[0])) break;
					sum1 += board[hx][hy];
					hx += dx[0];
					hy += dy[0];
					tmp1--;
				}
				if (tmp1 > 0) continue;
				
				int tt11 = hx;
				int tt22 = hy;

				for (int dir2 = 1; dir2 < n; dir2++) {
					hx = tt11; hy = tt22;
					int sum2 = 0;
					tmp1 = dir2;
					while (tmp1) {
						if (!InRange(hx + dx[1], hy + dy[1])) break;
						sum2 += board[hx][hy];
						hx += dx[1];
						hy += dy[1];
						tmp1--;
					}
					if (tmp1 > 0) continue;

					int tt111 = hx;
					int tt222 = hy;
					for (int dir3 = 1; dir3 < n; dir3++) {
						hx = tt111; hy = tt222;
						int sum3 = 0;
						tmp1 = dir3;
						while (tmp1) {
							if (!InRange(hx + dx[2], hy + dy[2])) break;
							sum3 += board[hx][hy];
							hx += dx[2];
							hy += dy[2];
							tmp1--;
						}
						if (tmp1 > 0) continue;
						int tt1111 = hx;
						int tt2222 = hy;

						
						for (int dir4 = 1; dir4 < n; dir4++) {
							hx = tt1111; hy = tt2222;

							int sum4 = 0;
							tmp1 = dir2;
							while (tmp1) {
								if (!InRange(hx + dx[3], hy + dy[3])) break;
								sum4 += board[hx][hy];
								hx += dx[3];
								hy += dy[3];
								tmp1--;
							}
							if (tmp1 > 0) continue;

							
							ans = max(ans, sum1 + sum2 + sum3 + sum4);

						}
					}
				}
			}
		}
	}


	cout << ans;
	return 0;
}