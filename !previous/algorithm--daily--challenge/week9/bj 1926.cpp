#include<iostream>
#include<queue>
using namespace std;

int map[502][502] = { 0 , };
int visit[502][502] = { 0, };


int main() {
    int n, m;
    cin >> n >> m;

    int num = 0;
    int mb = 0;

    queue<int> q;

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { -1,1,0,0 };


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            if (map[i][j] == 1 && visit[i][j] == 0) {
                num++;

                q.push(i * 1000 + j);
                visit[i][j] = 1;

                while (!q.empty()) {

                    cnt++;
                    int tmp = q.front();
                    int x = tmp / 1000;
                    int y = tmp % 1000;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int new_x = x + dx[k];
                        int new_y = y + dy[k];
                        //범위 초과 pass, 이미 방문 예정되어있거나 방문했었다면 pass
                        if ((0 > new_x) || (new_x > 500) || (new_y < 0) || (new_y > 500)) continue;
                       
                        if ((map[new_x][new_y] == 0) || visit[new_x][new_y]) continue;

                        q.push(1000 * new_x + new_y);
                        visit[new_x][new_y] = 1;


                    }
                }

                mb = max(mb, cnt);
            }
        }
    }

    cout << num << '\n' << mb;

    return 0;
}