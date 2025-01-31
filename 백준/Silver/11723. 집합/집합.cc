#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


bool arr[21];
void add(int x) {
	arr[x] = 1;
}

void remove(int x) {
	arr[x] = 0;
}

void check(int x) {
	if (arr[x]) cout << 1 << '\n';
	else cout << 0 << '\n';
}

void toggle(int x) {
	if (arr[x]) arr[x] = 0;
	else arr[x] = 1;
}

void all() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = 1;
	}
}


void empty() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str[1] == 'd') {
			int x; cin >> x;
			add(x);
		}
		else if (str[0] == 'c') {
			int x; cin >> x;
			check(x);
		}
		else if (str[0] == 'r') {
			int x; cin >> x;
			remove(x);
		}
		else if (str[0] == 't') {
			int x; cin >> x;
			toggle(x);
		}
		else if (str[0] == 'a') all();
		else if (str[0] == 'e') empty();
	}

	return 0;
}