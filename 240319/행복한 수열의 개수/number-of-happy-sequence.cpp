#include <iostream>
using namespace std;

int board[100][100];
int n,m;

bool is_happy(bool is_row, int col) {
	int seq = 1;
	for (int i = 1; i < n; i++) {
		int cnt = 1;

		if (is_row) {
			int pre = board[col][0];
			if (pre == board[col][i]) cnt++;
			else cnt = 1;
			seq = max(cnt, seq);
			pre = board[col][i];
		}
		else {
			int pre = board[0][col];
			if (pre == board[i][col]) cnt++;
			else cnt = 1;
			seq = max(cnt, seq);
			pre = board[i][col];

		}
	}
	return seq >= m;
}


int main() {
	int ans = 0;
	cin >> n >> m; 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
			ans += is_happy(true, i);
			ans += is_happy(false, i);
	}

	cout << ans;

	return 0;
}