// m번 사람 m분 출발
// n * n 격자

// 총 1분동안 1,2,3 순서로 진행

// 행동 3개
// 2. 편의점 도착 시 편의점에서 멈춤 (다른 사람들은 해당 편의점이 있는 칸 지나갈 수 없음) 
// (사람들이 모두 이동한 다음에야 칸을 지나갈 수 없음) (next time에 대한 배열)
// 3. t <= m을 만족한다면 자신이 가고 싶은 편의점과 가장 가까이 있는 베이스 캠프 들어감 (행이 작은, 행이 같다면 열이 작은 베이스캠프) 
// 베이스 캠프로 이동하는데 시간 소요 x 
// 다른 사람이 이동 불가

// 베이스캠프에서 이동 시작이네

// 총 몇 분 후에 사람들이 도착하는지

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; // n : 격자 수 , m : 사람 수
int map[15][15]; // 0 : 빈 공간, 1 : 베이스 캠프  2: 사람이 들어간 베이스 캠프 또는 편의점
// 음수는 사람 번호 (근데 둘 다 거기 있으면?) -> 사람은 따로 관리하자

// 사람의 위치는 어떻게 표현?? 
vector<pair<int,int>> people; // 사람의 위치 표현
vector<pair<int,int>> con; // 편의점 좌표
int time = 0;
int people_left;
int parent[15][15]; // 자신이 이전에 어디서 왔는지 기록할 곳 : 초기값 -1

// map과 편의점 좌표 받기
void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		con.push_back({ a,b });
	}

	people_left = m;
}

// 이거 해당 사람마다 bfs를 진행해야하나?
// 역추적 기법을 사용해서?
// 만약 이미 지나고 있는데 편의점이 되면? -> ㅇㅇ 일단 bfs 해야할 것 같음

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0,-1,1,0 };

// 경로 배열이 있으면 최단 경로 찾아주는 함수
vector<pair<int, int>> get_route(pair<int,int> p) { 
	vector<pair<int, int>> route;
	route.push_back(p);
	int hx = p.first;
	int hy = p.second;
	int next = parent[hx][hy];
	int nx = next / 100;
	int ny = next % 100;
	while (1) {
		if (hx == nx && hy == ny) break; // 자기 자신이 나올 때 까지
		route.push_back({ nx,ny });
		hx = nx; hy = ny;
		next = parent[hx][hy];
		nx = next / 100;
		ny = next % 100;
	}

	return route;
}


// 시간복잡도 O (N^2) : BFS
vector<pair<int,int>> find_sp(pair<int,int> st, pair<int,int> end) { // input : 출발지 좌표 + 목적지 좌표, output : 끝까지 가는 경로

	// 경로 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			parent[i][j] = -1;
		}
	}

	queue<pair<int,int>> q;
	q.push(st);
	parent[st.first][st.second] = st.first * 100 + st.second;

	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위를 나갔다면 
			if (map[nx][ny] > 1) continue; // 사람이 이미 찬 bs 또는 편의점이라면
			if (parent[nx][ny] != -1) continue; // 이미 방문한 곳이라면
			q.push({ nx,ny });
			parent[nx][ny] = hx * 100 + hy;

			if (nx == end.first && ny == end.second) { // 목적지 찾았다면 return
				return get_route({nx,ny});
			}
		}
	}

	return vector<pair<int, int>>();
}





// 해당 사람이 basecamp 찾는 함수
void find_bs(pair<int,int> cor) { // input : 해당 사람이 가고 싶은 편의점 좌표
	int x = cor.first;
	int y = cor.second;

	vector<tuple <int, int, int>> arr; // 편의점과의 거리, 행, 열

	// 가장 가까운 bs 찾기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				// 편의점 좌표, -> bs
				vector<pair<int, int>> route = find_sp(make_pair(i, j), make_pair( x,y )); // TD : 최단거리 구하기
				int dist = route.size();
				if (dist == 0) continue;
				arr.push_back({ dist,i,j }); // 편의점과의 거리가 가깝고, 행과 열 모두 작을수록 좋음 
			}
		}
	}

	sort(arr.begin(), arr.end());
	int bx = get<1>(arr[0]);
	int by = get<2>(arr[0]);
	map[bx][by] = 2; // map 금지구역
	people.push_back({ bx,by }); // 사람 위치 bs로 옮기기
}


// 모든 사람 움직이기
void move() {

	// 모든 사람 이동
	for (int i = 0; i < people.size(); i++) {
		if (people[i].first == -1) continue; // 이미 도착한 사람은 pass
		vector<pair<int,int>> path = find_sp(people[i], con[i]);
		people[i].first = path[path.size()-2].first; people[i].second = path[path.size() - 2].second;
	}
}

void stop() {
	// 만약 해당 사람이 편의점에 있다면 사람 이동 + 편의점 이동 
	for (int i = 0; i < people.size(); i++) {
		if (people[i].first == con[i].first && people[i].second == con[i].second) {
			people[i] = { -1,-1 };
			map[con[i].first][con[i].second] = 2;
			people_left--;
		}
	}
}

int main() {
	// map과 편의점 좌표 받기
	input();

	// 0~1분
	while (1) {
		// 사람마다 가고 싶은 편의점과 가장 가까운 베이스 캠프 선택 - 시점에 따라 다듦
		// t 분


		// 1. 격자에 있는 사람들 모두가 본인이 가고 싶은 편의점 방향을 향해서 최단거리로 움직임 (목적지와 도착지가 있는 bfs)

		move();

		// 2. 편의점에 도착하면 편의점  칸 못지나감 + 해당 사람은 이제 의미 없음 pair에 -1로
		stop();


		// 3. 사람 출발 - 베이스캠프에 위치한거 map에 기록
		if (time < m) {
			find_bs(con[time]);
		}

		time++;

		// 만약 종료 조건을 만족한다면 종료 - 모두 편의점에 도착
		if (people_left == 0) break;
	}

	cout << time; 
	return 0;
}