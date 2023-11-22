#include <iostream>
#include <vector>
using namespace std;
long long k, n;
vector<long long> arr;
long long max_x;
bool pos(int x) { long long ans = 0;  for (auto a : arr) { ans += a / x; } return ans >= n; }
int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		long long tmp; cin >> tmp; max_x = max(max_x, tmp);
		arr.push_back(tmp);
	}
	long long st = 1;
	long long ed = max_x + 1;
	while (st+1 != ed) {
		long long mid = (st + ed) / 2;
		if (pos(mid)) st = mid;
		else ed = mid;
	}
	cout << st;
	return 0;
}