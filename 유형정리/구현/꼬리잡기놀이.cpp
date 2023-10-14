#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 3명이상 한 팀 머리사람 꼬리사람

int map[20][20]; // 0 : 빈칸, 1 : 머리사람, 2: 머리사람과 꼬리사람이 아닌 나머지, 3: 꼬리사람 4: 이동 선
int n, m, k; // n : 격자 크기, m : 팀의 개수, k : 라운드 수 
int total_score; // 최종 값
vector<pair<int, int>> heads; // 머리 사람들 좌표 m == head.size()
int rd = 0;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				heads.push_back({ i,j });
		}
	}
}

void output() { cout << total_score;}


// 뱀 문제랑 상당히 비슷한 방법인 것 같다
vector<pair<int,int>> find_team(int x, int y) { // 현재 머리의 위치

	vector<pair<int, int>> team;
	int visit[20][20] = { 0 };

	queue<pair<int, int>> q;
	q.push({ x,y }); // 현재 머리 위치
	visit[x][y] = 1; // 현재 머리는 방문했음
	team.push_back({ x,y });


	// 꼬리 사람 찾기
	while (q.size()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = hx + dx[dir];
			int ny = hy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == 4) continue; // 라인이면 아무것도 없으니 넘김
			if (map[nx][ny] == 0) continue; // 빈칸이면 넘김
			if (hx == x && hy == y && map[nx][ny] == 3) continue;
			if (visit[nx][ny]) continue; // 만약 방문했다면 pass

			// 나머지 사람 
			visit[nx][ny] = 1;
			team.push_back({ nx,ny });
			q.push({ nx,ny });
		}
	}

	// 맨 마지막에는 hx, hy가 남고 이게 꼬리
	return team;
}

// 1. 머리 사람을 따라서 한 칸 이동, 머리 사람 앞으로 한 칸 이동시키기 + 꼬리 사람 지우기
void move() {
	// 머리사람이 이동할 칸은 머리사람 기준 하나씩 움직여보고 다음 칸
	for (int i = 0; i < m; i++) {
		int headx = heads[i].first;
		int heady = heads[i].second;

		// 해당 team의 좌표값들 구함
		vector<pair<int, int> > lines = find_team(headx, heady);

		//머리 한칸 이동시키고
		for (int dir = 0; dir < 4; dir++) {
			int nx = headx + dx[dir];
			int ny = heady + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (lines[1] == make_pair(nx, ny)) continue; // 내가 이전에 간 곳 pass 
			if (map[nx][ny] == 0) continue; // 빈칸이면 넘김

			// 머리 좌표 구하기
			heads[i] = { nx,ny };
		}


		// 기존 좌표들 하나씩 땡기기
		for (int z = 0; z < lines.size(); z++) {
			map[lines[z].first][lines[z].second] = 2;
			if (z == lines.size() - 2) map[lines[z].first][lines[z].second] = 3;
			if (z == lines.size() - 1) map[lines[z].first][lines[z].second] = 4;
		}

		map[heads[i].first][heads[i].second] = 1;
	}

}


// 2. round 마다 공 + 3. 공이 던져지는 경우 최초로 만나는 사람 k^2 && 머리사람 꼬리 사람 바꾸기
void ball() {
	// 2. round 마다 공
	int d = (rd / n) % 4; // 공 방향 정하기
	int num = rd % n; // 공 열 정하기
	
	int hx = 0;
	int hy = 0;

	// 만약 해당 방향으로 공을 던지는 경우
	if (d == 0) hx = num;
	else if (d == 1) { hy = num; hx = n - 1; }
	else if (d == 2) { hx = n - 1 - num; hy = n - 1; }
	else if (d == 3) hy = n - 1 - num;

	
	for (int i = 0; i < n; i++) {
		int nx = hx + i * dx[d]; // 공의 위치
		int ny = hy + i * dy[d];

		// 공이 사람 안지나치면 그냥 넘어감
		if (map[nx][ny] == 0 || map[nx][ny] == 4) continue;

		//만약 공이 사람을 쳤으면
		// 1. 해당 사람이 어떤 집단에 속하는지 -> 어떤 머리에 있는지
		// 만약 해당 집단에 속한다면 그 사람은 머리로부터 몇번 째 사람인지
		for (int z = 0; z < m; z++) {
			int headx = heads[z].first;
			int heady = heads[z].second;

			vector<pair<int, int> > lines = find_team(headx, heady);
			int score = 0;
			// 사람 있으면 점수 반영
			for (int ff = 0; ff < lines.size(); ff++)
				if (lines[ff] == make_pair(nx, ny)) 
					score = (ff+1) * (ff+1);
	
			if ( score==0 ) continue;
			else {
				//점수 더하기
				total_score += score;
				auto tail = lines[lines.size() - 1];
				map[headx][heady] = 3;
				map[tail.first][tail.second] = 1;
				// 전역변수 초기화 하기
				heads[z] = tail;
				return;
			}
		}


		return;
	}

}

int main() {

	// map 정보 받기
	input();

	while (rd < k) {

		move(); // 1. 머리 사람을 따라서 한 칸 이동  --- 7시 50분 (35분)

		ball(); // 2. round마다 공 +  // 3. 공이 던져지는 경우 최초로 만나는 사람 k^2 점수 얻음 && 머리사람 꼬리사람 방향 바꾸기
		// 4. 라운드 증가
		rd++;
	}

	output();
	return 0;
}

//8시 23분에 코드 다 짬 

// 전역 변수 이동 + i * move 8시 30분

// 8시 35분 y = ny로 고치고 case 3번에서 틀림

// 방향 생각 잘못해서 고침 8시 53분 case 4번 

// 꼬리가 계속 있는 경우 생각 못함 -> 9시 17분에 디버깅 완료

// 런타임 에러 test case 5번 , 방향 바뀌는거 생각 못함 ( n % 4 ,,)

