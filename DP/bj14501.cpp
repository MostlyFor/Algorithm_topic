#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 첫 번째 풀이

// 시간복잡도 : O(N) : N
// 공간복잡도 : O(N) : 3*N


int T[17]; // T[k] : k에서의 일을 처리하는데 걸리는 시간
int P[17]; // P[k] : k에서의 일을 처리하면 얻는 점수
int dp[17]; // dp[k] : k일 이후로 일을 할 수 있을 때 얻을 수 있는 최대 점수


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];

    // 뒤에서부터 생각하기 dp[k-1] = max(dp[k], P[k-1] + dp[i + T[k-1]]
    
    if (T[N - 1] == 1) dp[N - 1] = P[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        dp[i] = dp[i + 1];
        if(i + T[i] <=N)
            dp[i] = max(dp[i], P[i] + dp[i + T[i]]);
    }

    cout << dp[0];

    return 0;
}


// 두 번째 풀이

// 시간복잡도 : O(N) : N
// 공간복잡도 : O(N) : 3*N

/*
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <=N; i++)
        cin >> T[i] >> P[i];

    // dp[k] : k일 까지 있을 때 받을 수 있는 보상의 최댓값
    // e : 일이 끝나는 날
    for (int i = 1; i <= N; ++i) {
        dp[i] = max(dp[i], dp[i - 1]);

        int e = i - 1 + T[i];
        if (e <= N) {
            dp[e] = max(dp[e], dp[i - 1] + P[i]);
        }
    }

    cout << dp[N];
    return 0;
}
*/