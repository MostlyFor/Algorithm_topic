#include <iostream>
#include <vector>
using namespace std;

int dx[6] = { -1,0,1,0, -1,0};
int dy[6] = { 0,1,0,-1, 0,1};


void solve() {
    int n, m; cin >> n >> m;

    vector<int> balls;
    vector<int> balls_dirs;

    // 구슬의 정보 받기 (0번 ~ m-1번)
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        char dir; cin >> dir;
        x--; y--;
        // 구슬마다 번호를 붙여서 구슬로 관리
        balls.push_back(x * 100 + y);
        if (dir == 'U') balls_dirs.push_back(0);
        else if (dir == 'D') balls_dirs.push_back(2);
        else if (dir == 'R') balls_dirs.push_back(1);
        else if (dir == 'L') balls_dirs.push_back(3);
    }


    // 2N 번 이동
    int cnt = 2 * n;
    while (cnt--) {
        int map[50][50] = { 0 };
        // 구슬이 다음에 이동하는 경로
        for (int i = 0; i < m; i++) {
            // 이미 없어진 공은 생각 x
            if (balls[i] == -1) continue;
            int x = balls[i] / 100;
            int y = balls[i] % 100;
            int nx = x + dx[balls_dirs[i]];
            int ny = y + dy[balls_dirs[i]];
            // 만약 nx ny가 범위를 나갔다면 방향 반대로 바꾸기
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                balls_dirs[i] += 2;
                if (balls_dirs[i] >= 4) balls_dirs[i] %= 4;
                nx = x;
                ny = y;

            }

            // 새로 이동할 수 있는 경로에 저장하기
            map[nx][ny] += 1;
            balls[i] = nx * 100 + ny;
        }

        // 맵 확인하면서 중복되는 좌표 구하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 겹쳐있다면 중복 제거
                if (map[i][j] > 1) {
                    for (int ball = 0; ball < m; ball++) {
                        if (balls[ball] == i * 100 + j) balls[ball] = -1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        if (balls[i] >= 0) ans++;


    cout << ans << '\n';

}


int main() {

    int T; cin >> T;

    while (T--)
        solve();

    return 0;
}