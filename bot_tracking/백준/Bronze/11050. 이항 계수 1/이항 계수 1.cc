#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;

int ans = 0;
void f(vector<int>& arr, int sm) {
	if (arr.size() == k) {
		ans++; return;
	}

	for (int i = sm; i < n; i++) {
		arr.push_back(i);
		f(arr, i + 1);
		arr.pop_back();
	}
		
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	vector<int> tmp;
	f(tmp,0);
	cout << ans;
	return 0;
}