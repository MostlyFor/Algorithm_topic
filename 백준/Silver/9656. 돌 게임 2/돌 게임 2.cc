#include<iostream>

using namespace std;

// 처음에 상근
int n;

// dp[k] : 돌이 k개 남았을 때 무슨 수를 써서라도 먼저 시작하는 사람이 마지막 돌을 가져가는지
bool dp[1001];

void input() { cin >> n; }

int main() {
	input();
	
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] == false || dp[i - 3] == false;
	}

	if (!dp[n]) cout << "SK";
	else cout << "CY";

	return 0;
}