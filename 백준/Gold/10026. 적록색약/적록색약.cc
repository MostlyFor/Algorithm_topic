#include <iostream>
#include <vector>
#include <queue>
using namespace std;



vector<vector<char>> map;
int visit[100][100]; // 적록색약
int visit_normal[100][100]; // 정상인
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;

void f(int h) {
	int x = h / 1000; int y = h % 1000;
	if (visit_normal[x][y]) return;
	visit_normal[x][y] = 1;

	// 주변 노드 방문
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//만약 범위 밖이라면 방문 x 
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if(map[nx][ny] == map[x][y])
			f(nx * 1000 + ny);
	}
}

void f2(int h) {
	int x = h / 1000; int y = h % 1000;
	 
	if (visit[x][y]) return;
	visit[x][y] = 1;

	// 주변 노드 방문
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//만약 범위 밖이라면 방문 x 
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if ((map[x][y] == 'R') || (map[x][y] == 'G')) {
			if ((map[nx][ny] == 'R') || (map[nx][ny] == 'G'))
				f2(nx * 1000 + ny);
		}
		else if ((map[x][y] == 'B')&& (map[nx][ny] == 'B'))
			f2(nx * 1000 + ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	// 맵 입력받기
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vector<char> tmp;
		for (int j = 0; j < str.size(); j++) {
			tmp.push_back(str[j]);
		}
		map.push_back(tmp);
	}

	int area = 0;
	// 정상인 입장 dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit_normal[i][j]) continue;
			area++;
			f(1000 * i + j);
		}
	}
	cout << area << ' ';

	// 적록색약 입장 dfs
	area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j]) continue;
			area++;
			f2(1000 * i + j);
		}
	}

	cout << area;

	return 0;
}