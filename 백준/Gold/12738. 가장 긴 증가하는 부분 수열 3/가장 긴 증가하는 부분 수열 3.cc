#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}
	vector<int> dp(n, 1); // dp[k] = k 번째 원소를 포함하는 가장 긴 부분 수열
	vector<int> dp2; // arr2[i] = i 길이의 부분 수열을 유지할 때의 최솟값
	for (int i = 0; i < n; i++) {
		// 새로운 arr[i]가 어디 들어갈 수 있는지 탐색함
		auto k = lower_bound(dp2.begin(), dp2.end(), arr[i]);
		// 들어갈 자리가 맨 뒤면 맨 뒤에 들어감
		if (k == dp2.end()) {
			dp2.push_back(arr[i]);
		}
		// 들어갈 자리가 있으면 중간에 들어감
		else
			dp2[k-dp2.begin()] = arr[i];
	}

	cout << dp2.size();

	return 0;
}