#include <iostream>
using namespace std;

int board[100][100];
int n,m;

bool is_happy(bool is_row, int col) {
	int seq = 1;

	if (is_row) {
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (board[col][i-1] == board[col][i]) cnt++;
			else cnt = 1;
			seq = max(cnt, seq);
		}
	}
	else {
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (board[i-1][col] == board[i][col]) cnt++;
			else cnt = 1;
			seq = max(cnt, seq);
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