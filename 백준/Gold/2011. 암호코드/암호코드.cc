#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    // dp[i] : i부터 시작된 문자열이 해석될 수 있는 경우의 수
    vector<int> dp(s.size()+1, 0);
    dp[s.size()] = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        if ((i != s.size() - 1) &&  (s[i] - '0') + (s[i + 1] - '0') == 0) {
            cout << 0;
            return 0;
        }
        if (s[i] - '0' >= 3) dp[i] = dp[i + 1];
        else if (s[i] - '0' == 0)
            continue;
        else if (s[i] - '0' == 1) {
            if (i + 2 == s.size() + 1)
                dp[i] = dp[i + 1];
            else  dp[i] = dp[i + 1] + dp[i + 2];
        }
        else if (s[i] - '0' == 2) {
            // 2가 마지막으로 쓰인 경우
            if (i + 2 == s.size() +1)
                dp[i] = dp[i + 1];
            else {
                if (s[i + 1] - '0' >= 7)
                    dp[i] = dp[i + 1];
                else
                    dp[i] = dp[i + 1] + dp[i + 2];
                    }
        }

        dp[i] %= 1000000;
    }


    cout << dp[0];

    return 0;
}