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

// 시간복잡도 O()


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;



    while (n--) {

        int n; cin >> n;
        queue<pair<int, int>> q;
        
        int target; cin >> target;
        int nums[10] = {};
        for (int i = 0; i < n; i++) {
            int imp; cin >> imp;
            q.push({ i,imp });
            nums[imp]++;
        }

        int k = 10;

        vector<int> arr;
        while (k--) {
            if (q.empty()) break;
            while (nums[k]) {
                auto h = q.front();
                int node = h.first;
                int imp = h.second;

                if (imp == k) {
                    arr.push_back(q.front().first);
                    if (q.front().first == target) {
                        k = 0; cout << arr.size(); break;
                    }
                    q.pop();
                    nums[k]--;
                }

                else {
                    auto tmp = q.front(); q.pop();
                    q.push(tmp);
                }
            }
        }





        cout << '\n';
    }
    return 0;
}