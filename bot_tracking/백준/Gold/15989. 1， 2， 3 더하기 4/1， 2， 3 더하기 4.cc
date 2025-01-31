#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;

int n;
int main() {
    int tc; cin >> tc;

    while (tc--) {
        cin >> n;
        
        
        vector<int> arr(10001, 0);
        arr[0] = 1;
        // 1로만 채우면 1, (1, 2)로만 채우면 n/2 + 1
        for (int i = 0; i <= n; i++) {
            if (i - 3 < 0) arr[i] = i / 2 + 1;
            else arr[i] = arr[i-3] + (i / 2) + 1;
        }


        cout << arr[n] << '\n';
    }

    return 0;
}