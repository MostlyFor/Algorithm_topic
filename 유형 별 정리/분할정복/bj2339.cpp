#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

typedef pair<int, int> p;
#define X first
#define Y second
vector<vector<int>> map;


int f(p p1, p p2, int ver) {
    bool is_done = true;
    int jew = 0;

    for (int i = p1.X; i <= p2.X; i++) {
        for (int j = p1.Y; j <= p2.Y; j++) {
            if (map[i][j] == 1) {
                is_done = false;
                break;
            }
            if (map[i][j] == 2)
                jew++;
        }
    }

    // base case : 자를 수 없다면 그냥 return 
    if (is_done) {
        if (jew == 1) return 1;
        else return 0;
    }


    int cnt = 0;
    for (int i = p1.X; i <= p2.X; i++) {
        for (int j = p1.Y; j <= p2.Y; j++) {
            if (map[i][j] == 1) {
                int case1 = 0;
                int case2 = 0;
                bool is_pos = 1;
                // 세로로 자른 경우 -> 가로로 자름
                if (ver) {
                    for (int k = p1.Y; k <= p2.Y; k++) {
                        if (map[i][k] == 2) is_pos = 0;
                    }

                    if (p1.X <= i - 1) case1 = f(p1, { i - 1,p2.Y }, 0);
                    if (p2.X >= i + 1) case2 = f({ i + 1,p1.Y }, p2, 0);

                    if (is_pos)
                        cnt += case1 * case2;

                }

                // 가로로 자른 경우 -> 세로로 자름
                else if (!ver) {
                    for (int k = p1.X; k <= p2.X; k++) {
                        if (map[k][j] == 2) is_pos = 0;
                    }

                    if (p1.Y <= j - 1) case1 = f(p1, { p2.X,j - 1 }, 1);
                    if (p2.Y >= j + 1) case2 = f({ p1.X,j + 1 }, p2, 1);

                    if (is_pos)
                        cnt += case1 * case2;
                }

            }
        }
    }


    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;


    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            tmp.push_back(t);
        }
        map.push_back(tmp);
    }

    int ans = f({ 0,0 }, { n - 1,n - 1 }, 0) + f({ 0,0 }, { n - 1,n - 1 }, 1);

    if (ans) cout<< ans;
    else cout << -1;

    return 0;
}