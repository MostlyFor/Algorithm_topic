#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	s.push_back(' ');
	int ans = 0;
	string tmp;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			tmp.push_back(s[i]);
		}
		else {
			if (tmp.size() == 0) continue;
			tmp = "";
			ans++;
		}
	}

	cout << ans;
	return 0;
}