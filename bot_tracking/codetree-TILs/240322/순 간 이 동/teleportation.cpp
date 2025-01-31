#include <iostream>
#include <vector>
using namespace std;
int a, b, x, y;
int main() {
    cin >> a >> b >> x >> y;

    int ans = 1e9;

    // 1. a -> b
    ans = min(ans, abs(b-a));

    // 2. a -> x -> y -> b
    ans = min(ans, abs(a-x) + abs(y-b));
    // 3. a -> y -> x -> b
    ans = min(ans, abs(a-y) + abs(x-b));

    cout << ans;
    return 0;
}