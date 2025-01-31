#include<iostream>
#include<vector>
using namespace std;

int dp[10002];

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }


    for (int i = 1; i <= k; i++) {
        dp[i] = 100000;
        for (auto coin : coins) {
            if (coin > 10000) continue;
            if (i - coin >= 0)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    if (dp[k] == 100000) cout << -1;
    else cout << dp[k];

    return 0;
}