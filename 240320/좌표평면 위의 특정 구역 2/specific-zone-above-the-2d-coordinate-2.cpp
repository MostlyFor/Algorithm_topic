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
		int w1 = 1e9, w2 = 0;
		int h1 =1e9, h2 = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			w1 = min(w1, arr[j].first);
			w2 = max(w2, arr[j].first);
			h1 = min(h1, arr[j].second);
			h2 = max(h2, arr[j].second);
		}

		ans = min((w2 - w1) * (h2 - h1), ans);
	}

	cout << ans;
	return 0;
}