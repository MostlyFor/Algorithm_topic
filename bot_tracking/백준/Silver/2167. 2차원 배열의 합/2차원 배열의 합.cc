#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b; cin >> a >> b;
	vector<vector<int>> map;
	for (int i = 0; i <= a; i++) {
		vector<int> tmp;
		int n = 0;
		for (int j = 0; j <= b; j++) {
			if (i == 0) {
				tmp.push_back(0);
				continue;
			}
			if (j == 0) {
				tmp.push_back(0);
				continue;
			}
			int x = 0; cin >> x;
			n += x;
			tmp.push_back(n+ map[i - 1][j]);
		}
		map.push_back(tmp);
	}


	int cmd; cin >> cmd;

	while(cmd--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int area = map[x2][y2] - map[x2][y1 - 1] - map[x1 - 1][y2] + map[x1 - 1][y1 - 1];

		cout << area << '\n';
	}
	return 0;
}