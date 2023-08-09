#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 시간복잡도 : O(N * 10000 * (1 + 1/2 + 1/3 + ... 1/10000)) <= 2 * N * 10000 * ln M (ln 10000) + NlgN
// 공간복잡도 : O(M+N) : 2M + 3N

int dp[10001];
int weights[10000];
pair<int,pair<int,int>> things[100]; //weight, values, K

bool cmp(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
    if (a.first == b.first)
        if (a.second.first == b.second.first) {
            return a.second.second > b.second.second;
        }
        else return a.second.first > b.second.first;

    return a.first < b.first;
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        things[i] = { a,{b,c} };
    }

    // sort
    sort(things, things+N, cmp);

    for (int j = 0; j < N; j++) {
        int weight = things[j].first;
        int value = things[j].second.first;
        int K = things[j].second.second;
        int cnt = 0;
        while (K--) {
            if (weights[weight] >= M / weight) break;
            for(int i = M; i >= 1; i--) {
                if (i - weight < 0) break;
                dp[i] = max(dp[i], dp[i - weight] + value);
            }
            weights[weight]++;
        }
    }
    
    cout << dp[M];
    return 0;
}

