#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

// 투 포인터 사용하지 않은 일반적인 풀이

// 시간복잡도 O(NlogN) : 2 * NlogN
// 공간복잡도 O(N)

/*
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        arr.push_back(k);
    }
    int x; cin >> x;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (auto a : arr)
        if (binary_search(arr.begin(), arr.end(), x - a)) ans++;
    cout << ans/2;
    return 0;
}
*/


// 투 포인터 사용한 풀이

// 시간복잡도 O(NlogN) : NlogN + N
// 공간복잡도 O(N)
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        arr.push_back(k);
    }
    int x; cin >> x;
    sort(arr.begin(), arr.end());

    auto left = arr.begin();
    auto right = arr.end() - 1;
    int ans = 0;
    while (left < right) {
        int sum = *left + *right;
        if (sum == x) {
            left++; right--; ans++;
        }
        else if (sum < x)
            left++;
        else
            right--;
    }

    cout << ans;

    return 0;
}

