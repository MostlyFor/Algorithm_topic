#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

long long f(unordered_map<int, int>& dp, int A, int B, int C) {
    if (B == 1) {
        dp[B] = A % C;
        return A % C;
    }

    if (dp.find(B) != dp.end()) return dp[B];

    if (B % 2 == 1) {
        dp[B] = f(dp, A, B / 2, C)%C  * f(dp, A, B / 2 + 1, C) % C % C;
        return dp[B];
    }

    dp[B] = f(dp, A, B / 2, C) %C * f(dp, A, B / 2, C) % C %C;
    return dp[B];
}

int main() {
    unordered_map<int, int> dp;

    int A, B, C;
    cin >> A >> B >> C;

    cout << f(dp, A, B, C);
    return 0;
}