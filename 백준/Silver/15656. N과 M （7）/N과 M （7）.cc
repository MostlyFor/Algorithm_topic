#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> arr;
void input() {
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solve(vector<int> tmp, int sm) {
	if (tmp.size() == m) {
		for (auto num : tmp) cout << num << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		tmp.push_back(arr[i]);
		solve(tmp, i);
		tmp.pop_back();
	}
}

int main() {
	input();

	sort(arr.begin(), arr.end());
	solve(vector<int>(),0);

	return 0;
}