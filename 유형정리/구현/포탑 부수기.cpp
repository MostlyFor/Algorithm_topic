#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;


int map[10][10]; //공격력 적혀있음
int n, m, k; // n : 열, m : 행, k : 턴
int history[10][10]; // 해당 포탑이 가장 최근에 언제 공격했는지
int destroy[10][10];
int dx[4] = { 0,1,0,-1 }; //(우/하/좌/상)
int dy[4] = { 1,0,-1,0 };




void input() {
	cin >> n >> m >> k;

	// 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}


// 1. 공격자 선정
// 부서지지 않은 포탑 중 가장 약한 포탑
// 가장 약한 포탑의 정의 
// 1. 공격력이 가장 낮은 포탑이 2개 이상이라면 가장 최근에 공격한 포탑이 가장 약한 포탑 (모든 포탑은 시점 0에 모두 공격)
// 2. 가장 최근에 공격한 호탑이 2개 이상이라면, 행과 열의 합이 가장 큰 포탑이 가장 약한 포탑
// 3. 이거로도 안가려진다면 열 값이 가장 큰 값이 가장 약한 포탑
int select_attacker() {
	vector<tuple<int, int, int, int>> att; // 공격력, 어느 시점에 공격했는지, 열 값

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue; // 부서진 포탑 제외
			// 공격력이 낮을수록 우선순위, history가 클수록 우선순위, 행과 열의 합이 클수록, 열이 클수록 우선순위
			att.push_back(make_tuple(map[i][j], -history[i][j], -(i + j), -(j * 100 + i)));
		}
	}
	sort(att.begin(), att.end());

	//  att[0] : 공격자
	return -get<3>(att[0]);

}

// 2. 공격자의 공격 대상
// 자신을 제외한 가장 강한 포탑 공격

// 가장 강한 포탑 정의
// 1. 공격력이 가장 높은 포탑
// 2. 2개 이상이라면 공격한지 가장 오래된 포탑
// 3. 2개 이상이라면 행과 열이 합 가장 작을 때,
// 4. 열 값이 가장 작을 때 

int select_def(int x, int y) { // 공격자의 좌표

	vector<tuple<int, int, int, int>> def; // 공격력, 어느 시점에 공격했는지, 열 값
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;
			if (i == x && j == y) continue;
			// 공격력이 클수록, history가 작을수록 우선순위, 행과 열의 합이 작을수록, 열이 작을수록
			def.push_back(make_tuple(-map[i][j], history[i][j], i + j, j * 100 + i));
		}
	}

	sort(def.begin(), def.end());

	if (def.size() == 0) return -1;

	return get<3>(def[0]);
}

// 1. 레이저 공격
// 상하좌우 4개의 방향으로 움질일 수 있음
// 부서진 포탑이 있는 위치는 지날 수 없음
// 가장자리에서 막힌 방향으로 진행하고자 한다면, 반대편으로 나옴
bool laser(int x, int y, int a, int b) {

	// x ,y - 공격자, a, b - 공격대상자

	int map_parent[10][10] = { 0, }; // 역추적을 위한 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map_parent[i][j] = -1;
		}
	}

	queue<int> q;

	// 공격자 좌표
	q.push(100 * x + y);

	map_parent[x][y] = 100 * x + y; // 공격자의 부모는 공격자

	destroy[x][y] = 1; // 공격자는 관여됨

	while (!q.empty()) {
		int hx = q.front() / 100;
		int hy = q.front() % 100;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			nx = (nx + n) % n;
			ny = (ny + m) % m;

			if (map[nx][ny] == 0) continue; // 부서진 포탑이 있다면 넘기기
			if (map_parent[nx][ny] != -1) continue; // 방문을 이미 했다면 방문

			// 자신이 어디에서 왔는지 기록
			map_parent[nx][ny] = hx * 100 + hy;
			q.push(nx * 100 + ny);

			// 공격 대상에 도착 -> 이제 경로 추적
			if (nx == a && ny == b) q = queue<int>();
		}
	}

	// 만약 레이저가 공격이 불가능하다면 여기서 return
	if (map_parent[a][b] == -1) return false;


	// parent를 이용해서 경로 구하기
	int target = 100 * a + b;

	// 자기 자신의 부모가 자기 자신이라면
	while (target != x * 100 + y) {
		map[target / 100][target % 100] -= (map[x][y] / 2);
		destroy[target / 100][target % 100] = 1;
		if (target / 100 == a && target % 100 == b) map[target / 100][target % 100] += (map[x][y] / 2) - map[x][y];
		map[target / 100][target % 100] = max(map[target / 100][target % 100], 0); //음수가 되는거 방지
		// 이제 target 초기화
		target = map_parent[target / 100][target % 100];
	}
	return true;
}


// 2. 포탑 공격 - 공격자는 공격 영향 받지 않음
void ball(int x, int y, int a, int b) {

	destroy[x][y] = 1;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int nx = a + i;
			int ny = b + j;
			nx = (nx + n) % n;
			ny = (ny + m) % m;
			if (map[nx][ny] == 0) continue; // 부서진 포탑은 신경 안씀
			if (nx == x && ny == y) continue; // 공격자는 영향 안받음

			map[nx][ny] -= (map[x][y] / 2);

			if (nx == a && ny == b) map[nx][ny] += (map[x][y] / 2) - map[x][y];
			destroy[nx][ny] = 1;
			map[nx][ny] = max(map[nx][ny], 0);
		}
	}

	return;
}


int main() {

	input();
	int time = 0;

	while (time != k) {


		// 공격자 선정
		int att = select_attacker();
		int att_x = att % 100;
		int att_y = att / 100;

		// 공격 대상 선정
		int def = select_def(att_x, att_y);
		if (def == -1) break;
		int def_x = def % 100;
		int def_y = def / 100;
		map[att_x][att_y] += (n + m);// 공격자로 선정 -> n+m 만큼의 공격력 증가


		// destroy 배열 초기화
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) destroy[i][j] = 0;

		// 공격,
		if (!laser(att_x, att_y, def_x, def_y))
			ball(att_x, att_y, def_x, def_y);

		// 포탑 정비 - 공격과 무관 + 부서지지 않은 포탑
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (destroy[i][j] == 0 && map[i][j] > 0) map[i][j]++;

		// history (언제 공격 했는지) 초기화
		time++;
		history[att_x][att_y] = time;
	}

	int ans = 0;

	//output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(map[i][j], ans);
		}
	}

	cout << ans;

	return 0;
}