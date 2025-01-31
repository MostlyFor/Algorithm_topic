#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    int dp[100001] = { 0 };
    // 무게, 가치
   

    // n개가 물건의 종류
    // m이 최대 무게

    for (int i = 0; i < n; i++) {
        int a, b;
        //a가 무게, b가 가치
        cin >> a >> b;
        for (int j = k; j >=a; j--) {
            dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[k];
    return 0;
}