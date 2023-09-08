#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


bool map[100][100];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		for (int x = a; x < a + 10; x++)
			for (int y = b; y < b + 10; y++)
				map[x][y] = 1;
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j]) ans++;
		}
	}


	cout << ans;

	return 0;
}