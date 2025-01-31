#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
bool lamp[50][50];
int ans;
int chance;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			lamp[i][j] = s[j]-'0';
		}
	}
	cin >> chance;
}

void rec(int c, vector<bool> pos, int k) { // 검사하고자 하는 열의 번호, 가능성 있는 행들
	if (c == m && k%2 == 0) {
		int cnt = 0;
		for (int i = 0; i < n; i++) if (pos[i]) cnt++;
		ans = max(ans, cnt);
		return;
	}

	for (int type = 0; type < 2; type++) {
		vector<bool> pos2(n,0);
		int cnt = 0;
		if (type == 0) {
			for (int i = 0; i < n; i++) {
				if (pos[i] == 1 && lamp[i][c] == 1) {
					pos2[i] = 1; cnt++;
				}
			}
			if (cnt == 0) continue;
			rec(c + 1, pos2, k);
		}
		else if (type ==1 && k > 0) {
			for (int i = 0; i < n; i++) {
				if (pos[i] == 1 && lamp[i][c] == 0) {
					pos2[i] = 1; cnt++;
				}
			}
			if (cnt == 0) continue;
			rec(c + 1, pos2, k - 1);
		}
	}
}

void solve() {
	rec(0,vector<bool>(n, 1),chance); // 가능성 있는 행들만 넘기기
}

int main() {
	input();
	solve();

	cout << ans;
	return 0;
}