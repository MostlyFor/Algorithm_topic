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

// 시간복잡도 O()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int cnt = 0;
    int sum = 0;
    while (sum < n) {
        cnt++;
        sum += cnt;
    }


    if(cnt % 2) cout << 1 + sum - n << '/' << cnt + 1 - 1 - sum + n;
    // cnt 칸에 있음 cnt 칸이면 분모 + 분자 cnt + 1임
    else cout << cnt + 1 - 1 - sum + n << '/' << 1 + sum - n;
    
    return 0;
}