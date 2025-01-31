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
	int ans = 0;
	for (int i = arr.size()-1; i >= 0; i--) {
		ans += k / arr[i];
		k %= arr[i];
	}

	cout << ans;
	return 0;
}