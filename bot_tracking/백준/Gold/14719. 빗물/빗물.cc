#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int ans;
vector<int> level;
int main() {
	cin >> n >> m;
	
	int total = 0;

	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		level.push_back(tmp);
	}

	// 각 level에 채울 수 있으면 채우기
	// 벽에 둘러 쌓여 있는지 확인하기
	
	for (int i = 0; i < n; i++) {
		vector<int> walls;


		// 해당 높이에 벽이 있으면 추가
		for (int j = 0; j < m; j++) {
			if (level[j] > i) walls.push_back(j);
		}

		if (walls.size() <= 1) continue;
		for (int wall = 0; wall + 1 < walls.size(); wall++) {
			total += walls[wall + 1] - walls[wall] - 1;
		}
	}

	cout << total;
	return 0;
}