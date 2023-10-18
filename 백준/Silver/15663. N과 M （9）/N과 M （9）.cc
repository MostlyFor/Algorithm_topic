#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> arr;
bool visit[8]; // 해당 인덱스를 썻는지

void input() {
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solve(vector<int> tmp) { // before : 같은 level에서 직전에 나왔는지
	if (tmp.size() == m) {
		for (auto num : tmp) cout << num << ' ';
		cout << '\n';
		return;
	}

	int before = 0;

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue; // 이전에 넣은 인덱스라면 pass
		if (before == arr[i]) continue; // 같은 level에서 이전 값과 같으면 pass
		tmp.push_back(arr[i]);
		before = arr[i];
		visit[i] = 1;
		solve(tmp);
		tmp.pop_back();
		visit[i] = 0;
	}
}

int main() {
	input();

	sort(arr.begin(), arr.end());
	solve(vector<int>());
	return 0;
}