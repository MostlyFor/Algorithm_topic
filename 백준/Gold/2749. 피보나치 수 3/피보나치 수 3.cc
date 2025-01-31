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

// 시간복잡도 O() :
// 공간복잡도 O() : 

map<long long, long long> dp;

// f(x + k) = f(k+2)f(x-1) + f(k+1)f(x)
long long f(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    long long x = n / 2;
    long long k = n - x;
    if (dp.find(k - 1) == dp.end())
        dp[k - 1] = f(k - 1) % 1000000;
    if (dp.find(k) == dp.end())
        dp[k] = f(k) % 1000000;
    if (dp.find(x-1) == dp.end())
        dp[x-1] = f(x-1) % 1000000;
    if (dp.find(x-2) == dp.end())
        dp[x-2] = f(x-2) % 1000000;

    return ((dp[k-1] + 2*dp[k]) * dp[x - 1] + (dp[k]+dp[k-1]) * dp[x-2]) % 1000000;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n; cin >> n;

    cout << f(n);

    return 0;
}