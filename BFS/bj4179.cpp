#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 시간복잡도 : O(RC) : 2 * (4 * RC) + 2R + 2C
// 공간복잡도 : O(RC) : 3 * RC 

char map[1000][1000];
int mapF[1000][1000];
int mapP[1000][1000];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0,0 };
int r, c;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;

    int person = 0;
    vector<int> fire;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'J') {
                person = i * 1000 + j;
                mapP[i][j] = 1;
            }
            if (map[i][j] == 'F') {
                fire.push_back(i * 1000 + j);
                mapF[i][j] = 1;
            }
        }
    }


    queue<int> q1;
    queue<int> q2;
    
    q1.push(person);
    for(auto f:fire)
        q2.push(f);

    while (!q2.empty()) {
        int h = q2.front(); q2.pop();
        int hx = h / 1000;
        int hy = h % 1000;
        for (int i = 0; i < 4; i++) {
            int nx = hx + dx[i];
            int ny = hy + dy[i];
            if (map[nx][ny] == '#') continue;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (mapF[nx][ny]) continue;
            mapF[nx][ny] = mapF[hx][hy] + 1;
            q2.push(nx * 1000 + ny);
        }
    }
    
    while (!q1.empty()) {
        int h = q1.front(); q1.pop();
        int hx = h / 1000;
        int hy = h % 1000;
        for (int i = 0; i < 4; i++) {
            int nx = hx + dx[i];
            int ny = hy + dy[i];
            if (map[nx][ny] == '#') continue;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (map[nx][ny] == 'F') continue;
            if (mapP[hx][hy] + 1 >= mapF[nx][ny] && (mapF[nx][ny])) continue;
            if (mapP[nx][ny]) continue;
            mapP[nx][ny] = mapP[hx][hy] + 1;
            q1.push(nx * 1000 + ny);
        }
    }
    
    int ans = 10000000;
    for (int i = 0; i < r; i++) {
        if (mapP[i][0] != 0)
            ans = min(ans, mapP[i][0]);
        if (mapP[i][c-1] != 0)
            ans = min(ans, mapP[i][c-1]);
    }

    for (int i = 0; i < c; i++) {
        if (mapP[0][i] != 0)
            ans = min(ans, mapP[0][i]);
        if (mapP[r-1][i] != 0)
            ans = min(ans, mapP[r-1][i]);
    }

    if (ans == 10000000) cout << "IMPOSSIBLE";
    else cout << ans;
    
    return 0;
}

