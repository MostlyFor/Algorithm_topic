#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>

using namespace std;


// 시간복잡도 O(치킨집 개수 * (4 * N^2 * 2N) + 치킨집 개수! + 치킨집 개수! * 2N * 치킨집 개수)
// 공간복잡도 O()

int Map[50][50];
map<int, int> house_pos;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> combination;


// nCm을 하는 함수
void f(vector<int> &arr, int n, int m, int smallest) {
    if (arr.size() == m) {
        combination.push_back(arr);
        return;
    }

    for (int i = smallest; i < n; i++) {
        arr.push_back(i);
        f(arr, n, m, i + 1);
        arr.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    int n, m; cin >> n >> m;
    int house_cnt = 0;
    int chicken_cnt = 0;
    
    vector<int> chicken_pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 1) {
                house_pos[i * 100 + j] = house_cnt;
                house_cnt++;
            }
            if (Map[i][j] == 2) {
                chicken_pos.push_back(i * 100 + j);
                chicken_cnt++;
            }
        }
    }

    // 1. 현재 각 치킨집마다의 집까지의 거리 구하기, 치킨집마다 구현을 해줘야함! (치킨집 개수 x BFS)
    // 새로운 배열 c_dis[]에 저장
    vector<vector<int>> c_dis;

    for (int i = 0; i < chicken_pos.size(); i++) {
        queue<int> q;
        q.push(chicken_pos[i]);
        int visit[50][50] = { 0, };
        visit[chicken_pos[i] / 100][chicken_pos[i] % 100] = 1;
        vector<int> dis(house_cnt,0);

        while (!q.empty()) {
            int h = q.front(); q.pop();
            int hx = h / 100;
            int hy = h % 100;
            for (int i = 0; i < 4; i++) {
                int nx = hx + dx[i];
                int ny = hy + dy[i];

                if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
                if (visit[nx][ny]) continue;
                visit[nx][ny] = visit[hx][hy] + 1;
                q.push(nx * 100 + ny);
                if(Map[nx][ny] == 1)
                    dis[house_pos[nx * 100 + ny]] = visit[nx][ny];
            }
        }
        c_dis.push_back(dis);
    }

    // 2. 치킨집을 m개 선택하는 경우의 수를 저장함
    vector<int> arr;
    f(arr, chicken_cnt, m,0);

    // 3. 각 경우의 수 마다 도시 치킨 거리 구함
    int ans = 1e9;
    for (int i = 0; i < combination.size(); i++) {
        int ans_tmp = 0;
        for (int k = 0; k < house_cnt; k++) {
            int house_dist = 1e9;
            for (int j = 0; j < m; j++) {
                house_dist = min(house_dist, c_dis[combination[i][j]][k]);
            }
            ans_tmp += house_dist;
        }
        ans = min(ans, ans_tmp);
    }

    cout << ans - house_cnt;

    return 0;
}