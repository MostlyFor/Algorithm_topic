#include<iostream>

using namespace std;

// 처음에 상근
long long n;

// dp[k] : 돌이 k개 남았을 때 최선의 선택을 했을 때 먼저 시작하는 사람이 마지막 돌을 가져가는지
bool dp[1001];

void input() { cin >> n; }

int main() {
	input();
	
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;
	dp[4] = false;

	for (int i = 4; i <= n; i++) {
		dp[i] = !(dp[i - 1] || dp[i - 3] || dp[i - 4]);
	}

	if (!dp[n]) cout << "SK";
	else cout << "CY";

	return 0;
}