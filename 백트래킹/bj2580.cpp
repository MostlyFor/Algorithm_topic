#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

bool is_pos = 0;

int map[9][9];
vector<int> p;




void find_unused(vector<int> &arr , int x, int y) {
    for (int i = 0; i < 9; i++) {
        arr[map[x][i]]++;
    }

    for (int i = 0; i < 9; i++) {
        arr[map[i][y]]++;
    }
    x = x / 3 * 3;
    y = y / 3 * 3;

    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            arr[map[i][j]]++;
        }
    }
}

void f() {
    if (is_pos) return;

    int zero_cnt = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == 0) zero_cnt++;
        }
    }
    
    // basecase
    if (zero_cnt == 0) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << map[i][j] << ' ';
                }
                cout << '\n';
            }
            is_pos = true;
       return;
    }

    for (auto k : p) {
        int i = k / 10;
        int j = k % 10;
        if (map[i][j] == 0) {
            vector<int> arr(10, 0);
            find_unused(arr, i, j);
            for (int k = 1; k <= 9; k++) {
                if (arr[k] == 0) {
                    map[i][j] = k;
                    f();
                    if (is_pos) return;
                    map[i][j] = 0;
                }
            }
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++) 
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) p.push_back(10 * i + j);
        }

    f();


    return 0;
}