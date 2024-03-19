#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    while (n--) {
        int tmp; cin >> tmp;
        int cnt = 0;
        vector<int> arr;
        for (int i = 0; i < 20; i++) {
            int key; cin >> key;
            int line = lower_bound(arr.begin(), arr.end(), key) - arr.begin();
            cnt += arr.size() - line;
            arr.push_back(key);
            sort(arr.begin(), arr.end());
        }


        cout << tmp << ' ' << cnt << '\n';
    }
    return 0;
}