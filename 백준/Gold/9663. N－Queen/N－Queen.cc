#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
int n;
int col[16];

vector<int> check(int level) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		bool pos = 1;
		for (int k = 0; k < level; k++) {
			if (col[k] == i || k -col[k] == level - i || col[k]+k == level+i) pos = 0;
		}
		if (pos) arr.push_back(i);
	}

	return arr;
}

void solve(int dep) {
	// 만약 퀸 배치가 끝났다면
	if (dep == n) {
		ans++; return;
	}

	// 가능한 곳에 배치
	// 현재 가능한 위치들 확인
	vector<int> arr = check(dep);
	for (auto k : arr) {
		col[dep] = k;
		solve(dep + 1);
		col[dep] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < 16; i++) col[i] = -1;
	solve(0);
	cout << ans;

	return 0;
}