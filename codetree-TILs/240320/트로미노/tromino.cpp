#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[200][200];
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 2 < m; j++) {
			int cnt = board[i][j] + board[i][j + 1] + board[i][j + 2];
			ans = max(ans, cnt);
		}
	}

	for (int i = 0; i +2 < n ; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = board[i][j] + board[i+1][j] + board[i+2][j];
			ans = max(ans, cnt);
		}
	}

	for (int i = 0; i+1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			int cnt = board[i][j] + board[i + 1][j] + board[i+1][j + 1];
			ans = max(ans, cnt);
			cnt = board[i][j] + board[i][j+1] + board[i + 1][j + 1];
			ans = max(ans, cnt);
			cnt = board[i][j] + board[i + 1][j] + board[i][j + 1];
			ans = max(ans, cnt);
			cnt = board[i+1][j] + board[i][j+1] + board[i + 1][j + 1];
			ans = max(ans, cnt);
		}
	}

	cout << ans;
	return 0;
}