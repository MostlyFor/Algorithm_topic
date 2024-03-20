#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[20][20];
int ans = 0;

int get_gold(int x, int y, int level) {
	int total = 0;

	for (int i = x - level; i < x + level; i++) {
		for (int j = y - level; j < y + level; j++) {
			if (0 > i || 0 > j || n <= i || m <= j) continue;
			if (abs(i - x) + abs(j - y) > level)continue;
			total += board[i][j];
		}
	}

	return total;
}

// x ,y 에서 채굴 시작
int mining(int x, int y) {
	// k에 따른 마름모를 최대로 늘려가면서 한번 해보기
	int max_profit = board[x][y];
	int profit = board[x][y]; 
	int level = 0;
	while (profit > 0) {
		// - 채굴비용 + 채굴했을 때 얻는 금액
		level++;
		int cost = level * level + (level + 1) * (level + 1);
		profit = -cost + get_gold(x, y, level);
		max_profit = max(max_profit, profit);
	}


	return max_profit;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int profit = 1;
	int level = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, mining(i, j));
		}
	}
	


	cout << ans;
	return 0;
}