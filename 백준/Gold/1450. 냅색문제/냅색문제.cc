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

int n, c;
vector<int> things;
vector<long long> w1;
vector<long long> w2;
int ans;

// 시간복잡도 O(2 * 2^15 + NlogN + 2^15 * log2^15)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        things.push_back(tmp);
    }

    //물건 반으로 쪼개기

    int a = things.size() / 2;
    
    w1.push_back(0);
    for (int i = 0; i < a; i++) {
        int cnt = w1.size();
        for (int j = 0; j < cnt; j++) {
            w1.push_back(w1[j] + things[i]);
        }
    }

    w2.push_back(0);
    for (int i = a; i < things.size(); i++) {
        int cnt = w2.size();
        for (int j = 0; j < cnt; j++) {
            w2.push_back(w2[j] + things[i]);
        }
    }

    sort(w2.begin(), w2.end());
    
    int ans = 0;

    for (int i = 0; i < w1.size(); i++) {
        ans += lower_bound(w2.begin(), w2.end(), c - w1[i]+1) - w2.begin();
    }

    cout << ans ;

    return 0;
}