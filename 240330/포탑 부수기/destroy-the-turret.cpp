#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k; // n,m 격자, k는 턴 수 (만약 부서지지 않으 포탑이 1개가 된다면 끝남)

int board[10][10]; // 포탑 공격력
int btime[10][10]; // 최근 공격 시점
int dist[10][10]; // att와 def 거리 측정할 수 있게!
bool eff[10][10]; // 영향 받은 포탑 기록


int left_tower = 0; // 남아있는 포탑 수
int turn = 0;
pair<int, int> att; // 공격자
pair<int, int> def; // 공격 대상자

// 우선순위 우/하/좌/상
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
}



void check_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void check_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}




// 남아있는 포탑 중 가장 강한 포탑의 공격력
void output() {
    int max_power = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) max_power = max(max_power, board[i][j]);

    cout << max_power;
}

// 1. 공격자 + 공격 대상자 선정
void set_att() {
    vector<tuple<int, int, int, int>> arr; // 우선순위 배열 // 공격력 낮을수록, 시간 클수록, 행과열 합 클수록, 열 값 클수록

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) continue;
            tuple<int, int, int, int> tmp = make_tuple(-board[i][j], btime[i][j], i + j, j);
            arr.push_back(tmp);
        }
    }

    sort(arr.begin(), arr.end());

    // 좌표갱신
    def = { get<2>(arr[0]) - get<3>(arr[0]) , get<3>(arr[0])};
    att = { get<2>(arr.back()) - get<3>(arr.back()) , get<3>(arr.back())};
}

// att -> def 경로 확인
void get_route() {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dist[i][j] = 0;


    queue<pair<int, int>> q;
    q.push(att);
    dist[att.first][att.second] = 1;

    while (q.size()) {
        auto k = q.front(); q.pop();


        for (int i = 0; i < 4; i++) {
            int nx = k.first + dx[i];
            int ny = k.second + dy[i];

            // 좌표 범위 나가면 반대편 이동
            nx = (nx + n) % n;
            ny = (ny + m) % m;

            if (dist[nx][ny]) continue;
            if (board[nx][ny] == 0) continue;

            dist[nx][ny] = dist[k.first][k.second] + 1;
            q.push({ nx,ny });
        }
    }
}

// 2. 레이저 공격
void laser() {
    // dist 기반으로 경로 찾기
    vector<pair<int, int>> laser_route;
    laser_route.push_back(def);
    int hx = def.first;
    int hy = def.second;
    while (!(hx == att.first && hy == att.second)) {
        // 우선순위 반대로 돌면서 해결하기
        for (int i = 3; i >= 0; --i) {
            int nx = hx + dx[i];
            int ny = hy + dy[i];
            nx = (nx + n) % n;
            ny = (ny + m) % m;

            if (dist[nx][ny] == dist[hx][hy] - 1) {
                hx = nx; hy = ny;
                laser_route.push_back({ hx,hy });
                break;
            }
        }
    }


    // 경로 체크
    //for(auto aa : laser_route) cout << aa.first << ' ' << aa.second <<'\n';

    // 경로에 해당하는 애들 공격
    for (int i = 0; i < laser_route.size() - 1; i++) {
        auto aa = laser_route[i];
        if (i == 0) board[aa.first][aa.second] -= board[att.first][att.second];
        else board[aa.first][aa.second] -= board[att.first][att.second] / 2;

        eff[aa.first][aa.second] = true;
    }
}

// 2. 포탑 공격
void machine() {
    int hx = def.first;
    int hy = def.second;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = (hx + i + n) % n;
            int ny = (hy + j + m) % m;

            if (nx == hx && hy == ny) board[nx][ny] -= board[att.first][att.second];
            else if (board[nx][ny] != 0) board[nx][ny] -= board[att.first][att.second] / 2;

            eff[nx][ny] = true;
        }
    }
}


// 3. 부서진 포탑 처리 + 포탑 정비
void after_att() {

    eff[att.first][att.second] = true;
    eff[def.first][def.second] = true;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (board[i][j] < 0) board[i][j] = 0; // 해당 좌표가 공격을 받았다면
        if (board[i][j] != 0 && eff[i][j] == false) board[i][j]++;
    }
}


int main() {
    input();


    while (k--) {
        turn++;

        // 영향받은 애 초기화
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) eff[i][j] = 0;

        // 1. 공격자 선정 + 공격 대상자 선정  + att와 def 초기화
        set_att();

        // if() 만약 부서지지 않은 포탑이 하나라면 게임 끝
        if (att == def) break;

        // 수비자 공격력 추가
        board[att.first][att.second] += n + m;

        // att -> def 갈 수 있는지? + dist 초기화
        get_route();

        // 2. 포탑 공격
        if (dist[def.first][def.second]) laser(); // 레이져
        else machine(); // 포탑공격

        // 3. 부서진 포탑 처리 + 포탑 정비 + eff 초기화
        after_att();

        // 최근 공격 시간 갱신 time 초기화
        btime[att.first][att.second] = turn;
    }

    output();
    return 0;
}