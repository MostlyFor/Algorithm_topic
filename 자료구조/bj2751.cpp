#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

// 시간복잡도 O(NlogN)
// 공간복잡도 O(N)

vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    set<int> s;
    while (n--) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << '\n';

    return 0;
}

