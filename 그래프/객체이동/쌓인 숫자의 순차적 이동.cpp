#include<iostream>
#include <vector>

using namespace std;

int map[20][20];
int pos[401];
int parent[401];

int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1, };

// 시간복잡도 O(N^2 * M)
// -> 굳이 tree로 하지 말고 그냥 vector list로 만드는게 조금 더 편함 

// 해당 값의 최댓값 가져오기
int get_max(int value) {
	// 자신이 루트라면
	if (parent[value] == value) return value;
	// 루트가 아니라면
	return max(value, get_max(parent[value]));
}

// 해당 값의 최상단 부모 가져오기
int get_root(int value) {
	if (parent[value] == value) return value;
	return get_root(parent[value]);
}


// 해당 값의 최상단 부모 가져오기
int get_root(int value, int k) {
	if (parent[value] == k) return value;
	return get_root(parent[value],k);
}

int main() {
	int n, m;
	cin >> n >> m;

	// 처음 좌표 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			pos[map[i][j]] = i * 100 + j;
			parent[map[i][j]] = map[i][j];
		}
	}

	while (m--) {
		int k; cin >> k;
		// k의 현재 위치
		int hx = pos[k] / 100;
		int hy = pos[k] % 100;

		// 근처 최댓값 찾기
		int around_max = 0;
		for (int i = 0; i < 8; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			around_max = max(around_max, get_max(map[nx][ny]));
		}
		if (around_max == 0) continue; 
		// 근처 최댓값 좌표
		int new_x = pos[around_max] / 100;
		int new_y = pos[around_max] % 100;

		// pos - k의 좌표 수정, k 위에 있는 애들 모두 좌표 수정
		int k_p = k;
		while (parent[k_p] != k_p) {
			pos[k_p] = new_x * 100 + new_y;
			k_p = parent[k_p];
		}
		pos[k_p] = new_x * 100 + new_y;


		// parent, map 초기화 초기화 - 해당 좌표 마지막 수에 k 올리기, k직전 수의 부모 없애기
		int new_root = get_root(map[new_x][new_y]);
		parent[new_root] = k;

		// k가 최하단 원소일 경우
		if (map[hx][hy] == k) map[hx][hy] = 0;
		// 최하단 원소가 아닐 경우
		else {
			int before_value = get_root(map[hx][hy], k);
			parent[before_value] = before_value;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) cout << "None";
			else {
				vector<int> tmp;
				int map_tmp = map[i][j];
				while (parent[map_tmp] != map_tmp) {
					tmp.push_back(map_tmp);
					map_tmp = parent[map_tmp];
				}
				tmp.push_back(map_tmp);

				for (int i = tmp.size() - 1; i >= 0; i--)
					cout << tmp[i] << ' ';
			}

			cout << '\n';
		}
	}

	return 0;
}