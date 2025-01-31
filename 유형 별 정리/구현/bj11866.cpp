#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 1 2 3 4 5 6 7
	int n, k; cin >> n >> k;

	vector<int> arr;
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		arr.push_back(i);
		sum += i;
	}
	
	vector<int> ans;
	int i = 0;
	while (sum) {
		int cnt = 0;
		while (cnt < k) {
			i++;
			if (i > n) i = 1;
			if (arr[i]) cnt++;
		}

		arr[i] = 0;
		sum -= i;
		ans.push_back(i);
	}

	
	cout << '<';
	for (int i = 0; i < ans.size()-1; i++)
		cout << ans[i] << ", ";

	cout << ans.back() << '>';

	return 0;
}