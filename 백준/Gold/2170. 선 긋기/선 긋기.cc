#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <cmath>
#include <climits>
using namespace std;

typedef pair<int, int> p;
#define X first 
#define Y second


// 시간복잡도 O(NlogN) :
// 공간복잡도 O(N) : 

vector<p> pos;

bool cmp(p a, p b) {
    if (a.X == b.X)
        return a.Y > b.Y;
    return a.X < b.X;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    // 정렬 : nlogn 하고 lower_bound로 계속 찾자
    // 시간 log n 이자너ㅏ
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pos.push_back({ a,b });
    }

    sort(pos.begin(), pos.end(), cmp);

    auto iter = pos.begin();
    int min = (*iter).X;
    int max = (*iter).Y;
    int ans = max-min;
    iter = lower_bound(pos.begin(), pos.end(), make_pair(min,INT_MAX));
    while (iter != pos.end()) {
        int a = (*iter).X;
        int b = (*iter).Y;
        if (b > max) {
            // 중복 발생하면 중복 부분 제거
            if (max - a > 0) {
                ans -= max - a;
            }
            max = b;
            ans += b - a;
        }
        iter = lower_bound(pos.begin(), pos.end(), make_pair(a, INT_MAX));
    }

    cout << ans;


    return 0;
}