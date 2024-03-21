#include <iostream>
#include <vector>

using namespace std;
int T;

int main() {
	cin >> T;
	while (T--) {
		string str; cin >> str;
		int n; cin >> n;
		int len2 = 1e9;
		int len3 = -1;

		// k 번 등장 최소 길이
		// k 번 등장 최대 길이, but 앞 뒤 같음

		// 완탐 n^2
		// 모든 걸 탐험할 필요 없이 빈도 수 n개 이상인 단어만 탐색
		
		vector<int> abcd[26];
		for (int i = 0; i < str.size(); i++) {
			abcd[str[i] - 'a'].push_back(i);
		}

		for (int i = 0; i < 26; i++) {
			if (abcd[i].size() < n) continue;

			int l = 0;
			int r = n-1;
			while (r < abcd[i].size()) {
				len2 = min(len2, abcd[i][r] - abcd[i][l] + 1);
				len3 = max(len3, abcd[i][r++] - abcd[i][l++] + 1);
			}
		}

		if (len2 == 1e9) cout << -1 << '\n';
		else cout << len2 << ' ' << len3 << '\n';

	}
	return 0;
}