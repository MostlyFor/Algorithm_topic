#include <iostream>
using namespace std;

int dx[8] = { -1,1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };

int pos[400];

int map[20][20];


int main() {

    int n, m; cin >> n >> m;

    // 초기 상태 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            pos[map[i][j]] = i * 100 + j;
        }
    }

    // 시간반복
    while (m--) {
        // 그럼 숫자 1 ~ n 까지의 위치를 기억해두어야 하나? 아니면 매번 찾아야 하는데 n^2씩 들음 이거 n번씩 한다고 치면 n^3이라 그냥 저장해두는 게 나을듯 

        // 숫자 1에서 부터 반복
        for (int num = 1; num <= n * n; num++) {
            int x = pos[num] / 100;
            int y = pos[num] % 100;
            

            int max_around = 0;
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                max_around = max(max_around, map[nx][ny]);
            }

            // 최댓값 찾았으면 위치 서로 변경
            int max_x = pos[max_around] / 100;
            int max_y = pos[max_around] % 100;
            map[max_x][max_y] = num;
            map[x][y] = max_around;
            
            pos[num] = max_x * 100 + max_y;
            pos[max_around] = x * 100 + y;
        }
    }


    // 초기 상태 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}