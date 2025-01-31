#include <iostream>
using namespace std;

string s;

bool check(int left, int right) {
	right--;
	while (left <= right) {
		if (s[left++] != s[right--]) return false;
	}
	return true;
}

int main() {
	cin >> s;

	
	int length = s.size();
	if (check(0, length) == false) {
		cout << s.size();
		return 0;
	}
	
	char first = s[0];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != first) {
			cout << s.size() - 1;
			return 0;
		}
	}

	cout << -1;


	return 0;
}