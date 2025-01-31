#include<iostream>

using namespace std;

// 처음에 상근
long long n;

// dp[k] : 돌이 k개 남았을 때 최선의 선택을 했을 때 먼저 시작하는 사람이 마지막 돌을 가져가는지
//bool dp[1001];

void input() { cin >> n; }

int main() {
	input();
	
	int k = n % 7;

	if (k==0 || k==2) cout << "CY";
	else cout << "SK";

	return 0;
}