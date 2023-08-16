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


// 시간복잡도 O(N)
// 공간복잡도 O(N)

int dp[1000000];
int pos[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;

    vector<int> arr;
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pos[tmp] = i;
        arr.push_back(tmp);
    }


    int ans_max = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        int h = arr[i];
        // 내가 찾아야하는 h-1값이 내 이전 인덱스에 존재
        if (i > pos[h - 1]) dp[i] = dp[pos[h - 1]] + 1;
        ans_max = max(dp[i], ans_max);
    }


    cout << n - ans_max;

    return 0;
}