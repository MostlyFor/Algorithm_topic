#include<iostream>
#include <vector>

using namespace std;
int n, s;
vector<int> arr(100000,0);
int ans = 1e9;

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve() {
	int left = 0;
	int right = 1;
	int sum = arr[0];
	
	while (right <= n) {
		if (sum >= s) {
			ans = min(right - left, ans);
			sum -= arr[left];
			left++;
			if (ans == 1) return;
			continue;
		}
		if (right == n) return;
		sum += arr[right];
		right++;
	}
}

int main() {
	input();
	solve();
	if (ans != 1e9) cout << ans;
	else cout << 0;
	return 0;
}