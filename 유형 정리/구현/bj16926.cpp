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


//시간복잡도 O() : 
int N, M, R;
void rotate(vector<vector<int>>& map) {
    
    // 맨 처음에는 0, N-1에 대해 그 다음에는 1 N-2에 대해
    int u = 0;
    int d = N - 1;
    int l = 0;
    int r = M - 1;
    while ((u-1 != d) && (l-1 != r)) {
        //윗줄 왼쪽으로 이동
        int ul = map[u][l];
        for (int i = l; i <= r-1; i++) {
            map[u][i] = map[u][i + 1];
        }
        // 왼쪽 줄 아래로 이동
        int dl = map[d][l];
        for (int j = d; j >= u+1; j--) {
            map[j][l] = map[j-1][l];
        }
        map[u+1][l] = ul;
        
        //아랫쪽 줄 오른쪽으로 이동
        int dr = map[d][r];
        for (int i = r; i >= l+1; i--) {
            map[d][i] = map[d][i-1];
        }
        map[d][l + 1] = dl;

        //오른쪽 줄 위로 이동
        for (int j = u; j <= d-1; j++) {
            map[j][r] = map[j+1][r];
        }
        map[d - 1][r] = dr;

        u++; d--; l++; r--;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    while (R--) {
        rotate(map);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }

    
    return 0;
}