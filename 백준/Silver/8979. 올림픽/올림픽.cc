#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;


int n, k;

priority_queue<tuple<int, int, int, int>> pq;

int main() {
    cin >> n >> k;
    // 국가 K의 등수
    // 동점은 어떻게 처리?
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pq.push(make_tuple(b, c, d, -abs(a - k)));
    }

    int cnt = 0;
    while (1) {
        auto x = pq.top(); pq.pop();
        int n = get<3>(x);
        if (n == 0) break;
        cnt++;
    }

    cout << cnt + 1;

    return 0;
}