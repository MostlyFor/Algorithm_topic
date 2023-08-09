#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 동전의 조합을 구하는 문제이기 때문에 동전의 개수를 늘리면서 dp 적용

// 시간복잡도 : O(NK) :
// 공간복잡도 : O(N + K) : 

int dp[10001];
int coins[100];
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> value(n, 0);

    for (int i = 0; i < n; i++) cin >> value[i];

    for (int i = 0; i < n; i++) for (int j = value[i]; j <= k; j++) dp[j] += dp[j - value[i]];

    cout << dp[k];
    return 0;
}

