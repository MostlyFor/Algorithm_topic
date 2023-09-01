#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;


int ans_min = 1e9;
int ans_max = -1e9;
vector<int> arr;


void f(int num, int idx, vector<int> op) {
    if (op[0] + op[1] + op[2] + op[3] == 0) {
        ans_min = min(ans_min, num);
        ans_max = max (ans_max, num);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) continue;
        
        if (i == 0) {
            num += arr[idx];
            op[i]--;
            f(num, idx+1, op);
            op[i]++;
            num -= arr[idx];
        }
        if (i == 1) {
            num -= arr[idx];
            op[i]--;
            f(num, idx+1, op);
            op[i]++;
            num += arr[idx];
        }
        if (i == 2) {
            int tmp = num;
            num *= arr[idx];
            op[i]--;
            f(num, idx+1, op);
            op[i]++;
            num = tmp;
        }
        if (i == 3) {
            int tmp = num;
            if (tmp < 0) num *= -1;
            num = num / arr[idx];
            if (tmp < 0) num *= -1;
            op[i]--;
            f(num, idx+1, op);
            op[i]++;
            num = tmp;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    vector<int> op(4, 0);
    cin >> op[0];
    cin >> op[1];
    cin >> op[2];
    cin >> op[3];

    f(arr[0],1,op);

    cout << ans_max << '\n' << ans_min;

    return 0;
}