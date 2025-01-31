#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> arr;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		arr.push_back({ x,y });
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = min(ans, (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));
		}
	}

	cout << ans;
	return 0;
}