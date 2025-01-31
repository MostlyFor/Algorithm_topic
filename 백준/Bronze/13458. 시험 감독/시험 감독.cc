#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n; cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int b, c; cin >> b >> c;

	// 필요한 최소한의 감독 수

	// b + k(c), k = 0 ~ 

	long long ans = n;

	for (int i = 0; i < n; i++) {
		int res = max(0, arr[i] - b);
		ans += res / c;
		if (res % c) ans++;
	}
	

	cout << ans;


	return 0;
}