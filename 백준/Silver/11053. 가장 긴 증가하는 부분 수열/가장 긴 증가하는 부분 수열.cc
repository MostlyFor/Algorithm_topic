#include<iostream>
#include<vector>
#include <queue>

using namespace std;


int main() {

	int n; cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		numbers.push_back(tmp);
	}

	// dp[k] : k 번째 원소가 들어갔을 때의 최대 배열의 크기
	// k+1 번째 원소가 도착했을 때 k+1번재의 

	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (numbers[j] < numbers[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	

	int ans = 0;
	for (auto i : dp)
		ans = max(ans, i);


	cout << ans;
	return 0;
}