#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int n, m;

long long sum(int k) {
	long long trees = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= k) break;
		trees += arr[i] - k;
	}
	return trees;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int st = 0;
	int ed = arr[n - 1];
	while (st + 1 < ed) {
		int mid = (st + ed) / 2;
		if (sum(mid) >= m) { // mid는 가능
			st = mid;
		}
		else { // mid 까지 불가능 
			ed = mid;
		}
	}

	cout << st;

	return 0;
}