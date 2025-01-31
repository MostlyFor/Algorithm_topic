#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b; cin >> a >> b;

	vector<int> arr(a+1, 1);
	for (int i = 2; i <= a; i++) {
		for (int j = 1; j * i <= a; j++) {
			if (arr[j * i]) {
				arr[j * i] = 0;
				b--;
			}

			if (b == 0) {
				cout << j * i;
				return 0;
			}
		}
	}
	return 0;
}