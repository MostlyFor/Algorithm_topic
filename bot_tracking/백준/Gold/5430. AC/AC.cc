#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;

int main() {
	// Reverse 와 Drop
	// Reverse O(1) Drop O(1)
	cin >> T;
	while (T--) {
		string str; cin >> str;
		int n; cin >> n;
		vector<int> arr;
		string arr2; cin >> arr2;
		

		if (n != 0) {
			string tmp = "";
			// 문자열 입력
			for (int i = 0; i < arr2.size(); i++) {
				if ('0' <= arr2[i] && arr2[i] <= '9') tmp += arr2[i];

				else if (arr2[i] == ',' || arr2[i] == ']') {
					arr.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}

		int l = 0;
		int r = arr.size(); // 다음에 지워질 수
		bool dir = true;
		for (auto cmd : str) {
			if (cmd == 'R')
				dir = !dir;
			else {
				if (dir) l++;
				else r--;
			}
		}

		vector<int> ans;

		if (l > r) cout << "error" << '\n';
		else if (l == r) cout << '[' << ']' << '\n';
		else {
			if (dir) {
				for (int i = l; i < r; i++) ans.push_back(arr[i]);
			}


			else {
				for (int i = r - 1; i >= l; i--) ans.push_back(arr[i]);
			}



			cout << '[';
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i];
				if (i != ans.size() - 1) {
					cout << ',';
				}
			}
			cout << ']';

			cout << '\n';
		}
	}


	return 0;
}