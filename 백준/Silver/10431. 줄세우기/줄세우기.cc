#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    while (n--) {
        int tmp; cin >> tmp;
        int cnt = 0;
        vector<int> arr(20, 0);
        for (int i = 0; i < 20; i++) {
            cin >> arr[i];

            for (int j = 0; j < 20; j++) if (arr[i] < arr[j]) cnt++;
        }


        cout << tmp << ' ' << cnt << '\n';
    }
    return 0;
}