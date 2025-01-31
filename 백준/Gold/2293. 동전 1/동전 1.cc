#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}
	
	int dp[10001] = {};
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - arr[i] < 0) continue;
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];
	return 0;
}