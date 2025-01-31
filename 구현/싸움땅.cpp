#include<iostream>
#include<vector>
#include <queue>
using namespace std;


priority_queue<int> map[20][20]; // 총의 정보들이 기록되어 있는 곳
struct P {
	int x, y, d, abl; // x, y, d 방향 abl ; 초기 능력치
	int point = 0; // 획득한 포인트
	int gun = 0; // 가지고 있는 총
};

vector<P> people;

int n, m, k; // n : amp 크기, m : 사람 수 , k : 라운드 수
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void input() {
	cin >> n >> m >> k;

	// map : 총 정보 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			if (tmp == 0) continue;
			map[i][j].push(tmp); // 총의 공격력은 음수로 들어감
		}
	}

	// 명의 플레이어 정보 받기 - 플레이어 위치, 방향 초기 능력치
	for (int i = 0; i < m; i++) {
		P tmp;
		cin >> tmp.x >> tmp.y >> tmp.d >> tmp.abl;
		tmp.x--; tmp.y--;
		people.push_back(tmp);
	}
}

// 각 플레이어들이 획득한 포인트
void output() {
	for (int i = 0; i < m; i++) {
		cout << people[i].point << ' ';
	}
}


// 1-1 본인이 향하고 있는 방향대로 한 칸 이동, if 나가면 방향 바꾸기
void move(int idx) {
	int nx = people[idx].x + dx[people[idx].d];
	int ny = people[idx].y + dy[people[idx].d];

	// 만약 방향 나갔다면 반대 방향으로 이동 
	if (0 > nx || 0 > ny || nx >= n || ny >= n) {
		people[idx].d = (people[idx].d + 2) % 4;
		nx = people[idx].x + dx[people[idx].d];
		ny = people[idx].y + dy[people[idx].d];
	}

	people[idx].x = nx;
	people[idx].y = ny;
}

int find_player(int idx) { // 해당 칸에 플레이어 있는지 확인
	int hx = people[idx].x;
	int hy = people[idx].y;

	int num = -1;

	for (int i = 0; i < m; i++) {
		if (idx == i) continue;
		int x = people[i].x;
		int y = people[i].y;

		if (hx == x && hy == y) num = i;
	}

	return num;
}

void pick_gun(int idx) { // 2-1 그냥 총 줍는데, 이미 총 가지고 있는 경우 가장 공격력 큰 총 가지기
	int hx = people[idx].x;
	int hy = people[idx].y;


	// 해당 칸에 총이 없는 경우 그냥 넘어감 
	if (map[hx][hy].size() == 0) return;

	// 플레이어가 총을 가지고 있지 않은 경우
	if (people[idx].gun == 0) {
		people[idx].gun = map[hx][hy].top(); // 총의 공격력은 음수로 들어감
		map[hx][hy].pop();
	}

	// 총을 가지고 있는 경우
	else {
		if (people[idx].gun >= map[hx][hy].top()) return;
		// 격자의 총이 더 강한 경우
		else {
			map[hx][hy].push(people[idx].gun); // 플레이어 총 격자에 두고
			people[idx].gun = map[hx][hy].top(); // 공격력 가장 높은거 가져옴
			map[hx][hy].pop();
		}
	}
}

// 2-2-2 진 플레이어 행동 - 총 격자에 내려놓고 한 칸 이동
void loser(int idx) {
	int hx = people[idx].x;
	int hy = people[idx].y;


	
	// 총 격자에 내려놓고
	if (people[idx].gun != 0)
		map[hx][hy].push(people[idx].gun);
	people[idx].gun = 0;

	// 원래 방향대로 한 칸 이동
	for (int i = 0; i < 4; i++) {
		int d = (people[idx].d + i) % 4;

		int nx = hx + dx[d];
		int ny = hy + dy[d];
		// 해당 칸에 있으면 다른 방향 찾기
		if (0 > nx || 0 > ny || nx >= n || ny >= n) continue;
		// 해당 칸에 다른 사람 있으면 다시 다른 방향 찾기
		bool check = false;

		for (int i = 0; i < m; i++) {
			if (idx == i) continue;
			int x = people[i].x;
			int y = people[i].y;
			// 만약 해당 칸에 사람 있으면 
			if (nx == x && ny == y) check = true;
		}

		if (check) continue;

		// 이동가능 한 경우
		if (map[nx][ny].size() != 0) { // 총이 있다면
			people[idx].gun = map[nx][ny].top();
			map[nx][ny].pop();
		}

		// 좌표 옮기기
		people[idx].x = nx;
		people[idx].y = ny;

		// 방향 바꾸기
		people[idx].d = d;
		return;
	}
}

// 승리한 칸에 떨어져 있는 총들과 원래 들고 있던 총 중 가장 높은거 획득
void winner(int idx) {

	int hx = people[idx].x;
	int hy = people[idx].y;

	if (map[hx][hy].size() != 0) { // 총이 있다면
		if (people[idx].gun != 0)  map[hx][hy].push(people[idx].gun);
		people[idx].gun = map[hx][hy].top();
		map[hx][hy].pop();
	}
}

// idx : 이동자, pm : 싸움 걸리는 사람
// 2-2, 해당 격자에 플레이어가 있는 경우
void fight(int idx, int pm) {
	// 승패 정함 - 느엵치 : 초기 능력치 + 공격력 합

	int idx_score = people[idx].abl + people[idx].gun;
	int pm_score = people[pm].abl + people[pm].gun;

	int get_point = abs(idx_score - pm_score);

	if (idx_score == pm_score) {
		// idx의 초기 능력치ㅏㄱ 더 높음
		if (people[idx].abl > people[pm].abl) {
			people[idx].point += get_point;
			loser(pm); winner(idx);
		}
		else {
			people[pm].point += get_point;
			 loser(idx); winner(pm);
		}
	}

	else {
		// idx의 총 능력치가 높은 경우
		if (idx_score > pm_score) {
			people[idx].point += get_point;
			 loser(pm); winner(idx);
		}
		// pm이 이김
		else {
			people[pm].point += get_point;
			 loser(idx); winner(pm);
		}
	}
}


// 순차적으로 사람 이동
void action(int idx) {
	// 1-1 - 본인이 향하고 있는 방향대로 한 칸 이동, if 방향 바꾸기 

	move(idx);

	// 2-1 해당 칸에 플레이어 있는지 확인
	int pm = find_player(idx);

	if (pm == -1) 
		pick_gun(idx); // 사람 없으면 그냥 총 줍고 끝냄
	else 
		fight(idx, pm); // 사람 있으면 싸움

}

int main() {

	input();


	while (k--) {
		// 순차적으로 사람 행동
		for(int i=0; i<m; i++)
			action(i);
	}


	output();

	return 0;
}