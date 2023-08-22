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

// 시간복잡도 O(NogN + KlogK + KlogN)

// 1. 현재 가방에 넣을 수 있는 가장 큰 가치있는 물건을 넣자! (찾아야 하는 대상, 처음 접근 방향)
// 2. 가장 가치가 높은 보석을 넣을 수 있는 가장 작은 가방에 넣자 !

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, K; cin >> n >> K;
    long long ans = 0;

    vector<pair<int, int>> jews;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        jews.push_back({ a, b });
    }


    vector<int> bags;
    for (int i = 0; i < K; i++) {
        int a; cin >> a;
        bags.push_back(a);
    }

    // 가방은 무게 순으로 정렬 (오름차순)

    sort(jews.begin(), jews.end());
    sort(bags.begin(), bags.end());


    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < K; i++) {
        while (j != n && jews[j].first <= bags[i]) {
            pq.push(jews[j].second);
            j++;
        }

        if (pq.empty()) continue;

        ans += pq.top(); pq.pop();
    }


    cout << ans;


    return 0;
}