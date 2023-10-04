#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int map[20][20];
int dist_map[20][20];
int shark_size = 2;
int shark_start;
int shark_eat;
int time;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void bfs() {

	queue<int> q;
	q.push(shark_start);

	while (!q.empty()) {
		int hx = q.front() / 100;
		int hy = q.front() % 100;
		q.pop();

		// 갈 수 있는 방향 다 가보기
		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			// 범위
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			// 상어보다 몸무게 많은 칸
			if (map[nx][ny] > shark_size) continue;
			// 이미 방문한 칸
			if (dist_map[nx][ny] != 0) continue;

			q.push(nx * 100 + ny);
			dist_map[nx][ny] = dist_map[hx][hy] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	// 맵 정보 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) shark_start = i * 100 + j;
		}
	}



	while (1) {
		// 최단 거리 배열 초기화
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist_map[i][j] = 0;

		dist_map[shark_start/100][shark_start % 100] = 1;

		// 최단 거리 dist_map 
		bfs();
		// dist_map을 가지고 내가 다음에 가야하는 물고기 위치 구함
		vector<tuple<int, int, int>> targets;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 상어가 먹을 수 있는 물고기 중
				if (map[i][j] < shark_size && map[i][j] >= 1) {
					if (dist_map[i][j] == 0) continue;
					//거리가 가장 가까운애, 가장 위에 있고, 왼쪽에 있는 애 순으로 우선순위
					targets.push_back(make_tuple(dist_map[i][j], i , j));
				}
			}
		}

		// 만약 갈 수 있는 물고기가 없으면 그냥 여기서 종료
		if (targets.size() == 0) {
			cout << time; return 0;
		}

		sort(targets.begin(), targets.end());
		// 물고기 위치 구했으면 물고기 위치로 상어 이동시키고 크기 증가시킴!

		// 상어 크기, 시간, 상어 위치 변경
		int target = get<1>(targets[0]) * 100 + get<2>(targets[0]);
		map[shark_start / 100][shark_start % 100] = 0;
		shark_start = target;
		map[shark_start / 100][shark_start % 100] = 9999;
		time += get<0>(targets[0]) -1 ;
		shark_eat++;
		if (shark_eat >= shark_size) {
			shark_size++; shark_eat = 0;
		}
	}
	return 0;
}