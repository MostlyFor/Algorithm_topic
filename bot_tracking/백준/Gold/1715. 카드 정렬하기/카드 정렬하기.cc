#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	priority_queue<long long> pq;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		pq.push(-arr[i]);
	}

	while (pq.size() > 1) {
		long long a = -pq.top(); pq.pop();
		long long b = -pq.top(); pq.pop();
		ans += a + b;
		pq.push(-(a + b));
	}
	
	cout << ans;

	return 0;
}
