#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			arr.push_back(tmp);
		}

		int tgt; cin >> tgt;

		int dp[10001] = { 1, }; // dp[k] : k원을 만드는 방법 수

		for (int i = 0; i < arr.size(); i++) {
			int k = arr[i];
			for (int j = k; j <= tgt; j++) {
				dp[j] += dp[j - k];
			}
		}

		cout << dp[tgt]<< '\n';

	}
	return 0;
}