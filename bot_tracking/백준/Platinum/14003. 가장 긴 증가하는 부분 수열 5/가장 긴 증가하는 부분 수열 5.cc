#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr;

int parent[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;

	vector<int> arr(n,0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		parent[i] = i;
	}

	vector<pair<int, int>> dp; // dp[k] : k까지의 부분 수열을 유지할 때의 최솟값
	for (int i = 0; i < n; i++) {
		auto p = lower_bound(dp.begin(), dp.end(), make_pair(arr[i],-1));
		// 들어갈 자리가 없으면 가장 큰 수니까 맨 뒤
		if (p == dp.end()) {
			dp.push_back({ arr[i], i });
			// 맨 처음 들어가는 원소는 이게 없음
			if (dp.size()>=2)
				parent[i] = dp[dp.size()-2].second;
		}
		else {
			dp[p - dp.begin()] = { arr[i], i };
			if (p - dp.begin() != 0)
				parent[i] = dp[(p - dp.begin()) - 1].second;
		}
	}

	cout << dp.size() << '\n';

	int last = dp.back().second;

	vector<int> tmp;
	while (last != parent[last]) {
		tmp.push_back(arr[last]);
		last = parent[last];
	}
	tmp.push_back(arr[last]);

	for (int i = tmp.size() - 1; i >= 0; i--)
		cout << tmp[i] << ' ';
	return 0;
}