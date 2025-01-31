#include <iostream>
#include <vector>
using namespace std;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // dp[k] = s, k 번째 인덱스는 최대 s를 가지는 홀수 펠린드롬
    // dp2[k] = s, k번과 k+1 번째 인덱스를 중심으로 최대 s를 가지는 짝수 펠린드롬

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < n) {
            if (arr[left--] == arr[right++])
                dp[i] += 1;
            else break;
        }
    }

    vector<int> dp2(n, 0);
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != arr[i+1]) continue;
        dp2[i] = 1;
        int left = i - 1;
        int right = i + 2;
        while (left >= 0 && right < n) {
            if (arr[left--] == arr[right++]) {
                dp2[i] += 1;
            }
            else break;
        }
    }

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        int st, end;
        cin >> st >> end;

        //홀수 펠린드롬 처리
        int mid = st + end;
        if (mid % 2 == 0) {
            // 펠린드롬 한 변의 길이 <= 펠린드롬 크기 
            if ((end - st) / 2 + 1 <= dp[mid / 2 - 1]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        // 짝수 펠린드롬 처리
        else {
            int mid1 = mid / 2;
            // 펠린드롬 한 변의 길이 <= 펠린드롬 크기
            if ((end - st + 1) / 2 <= dp2[mid1 - 1]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }


    return 0;
}