#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    auto l = arr.begin();
    auto r = arr.end()-1;
    int left = 0;
    int right = 0;
    int sum = 1e9 * 2;
    
    while (l < r) {
        if (abs(*l + *r) < sum) {
            left = *l; right = *r;
            sum = abs(left + right);
        }

        if (*l + *r > 0) r--;
        else if (*l + *r <= 0) l++;

    }

    cout << left << ' ' <<right;

    return 0;
}