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


//시간복잡도 O(N * 100) : 


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin.ignore(256, '\n');
        string s;
        cin >> s;
        bool abcd[26] = { 0, };
        ans++;

        for (int j = 0; j < s.size(); j++) {
            char ch = s[j];
            if ((abcd[ch - 'a']) && (s[j - 1] != s[j])) {
                ans--;
                break;
            }
            abcd[ch - 'a'] = true;
        }
    }
    
    cout << ans;
    return 0;
}