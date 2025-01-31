#include <iostream>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int map[20][20];
int ball[20][20];
int ball_next[20][20];


int main() {
    // 1초에 어떻게 움직이는지 확인하기
    int n, m, t; cin >> n >> m >> t; // m은 구슬의 개수

    // 맵 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 구슬의 위치 표시하기
    while (m--) {
        int x, y; cin >> x >> y;
        ball[x-1][y-1] = 1;
    }

    // 1초 이후부터 시작
    while (t--) {
        // t+1 초에서 구슬의 이동 위치 구하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 구슬이 있는 경우
                if (ball[i][j] == 1) {
                    // 가장 점수가 큰 곳 찾기
                    int max_score = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        max_score = max(max_score, map[nx][ny]);
                    }

                    // 원래 있던 칸이 제일 높다면 그냥 넘어감
                    if (map[i][j] > max_score) continue;

                    // 상하좌우 순서대로 이동
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        // 이동할 곳이라면 다음 시점의 칸에 올려줌
                        if (map[nx][ny] == max_score) {
                            ball_next[nx][ny] += 1;
                            break;
                        }
                    }
                }
            }
        }

        // t+1 칸에 있는 정보들을 현재 정보로 바꾸기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 공이 하나
                if (ball_next[i][j] == 1) ball[i][j] = 1;
                else ball[i][j] = 0;
                ball_next[i][j] = 0;
            }
        }
    }

    int balls_left = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ball[i][j]) balls_left++;
        }
    }
    
    cout << balls_left;

    return 0;
}