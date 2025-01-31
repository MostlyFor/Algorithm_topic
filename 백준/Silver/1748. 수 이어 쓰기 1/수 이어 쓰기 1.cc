#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long  ans = 0;
	int n; cin >> n;
	// n이 몇 자리 수인지
	
	// 1의 자리수 ~ 1 x 9 - 1 x 0
	// 10의 자리수 ~ 2 x 99 - 2 x 9

	int cnt = 1; // 자릿수
	int k = 10; //
	while (n >= k) {
		ans += (cnt * (k -1)) - (cnt * (k/10-1));
		k *= 10;
		cnt++;
	}

	//남은건 cnt 자릿수 계산
	ans += (n - (k / 10) + 1) * cnt;

	cout << ans;
	return 0;
}