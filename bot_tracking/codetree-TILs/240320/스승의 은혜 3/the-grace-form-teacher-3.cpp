#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b;
int ans;
vector<int> arr[2];
vector<int> present;
int main() {
	cin >> n >> b;
	
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		arr[0].push_back(x);
		arr[1].push_back(y);
		present.push_back(x + y);
	}

	for (int i = 0; i < n; i++) {
		int people = 0;
		int cost = 0;
		vector<int> tmp(present.size());
		copy(present.begin(), present.end(), tmp.begin());
		tmp[i] -= arr[0][i]/2;
			

		sort(tmp.begin(), tmp.end());

		// people 번째 학생의 선물을 줄 수 있음
		while (b >= cost + tmp[people]) {
			cost += tmp[people++];
		}

		ans = max(ans, people);
	}


	cout << ans;
	return 0;
}