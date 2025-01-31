#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 물건을 하나씩 늘려가면서 하는 풀이

// 시간복잡도 : O(NK) : NK
// 공간복잡도 : O(K) : K

int dp[100001];
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N, K;
    cin >> N >> K;
    
    for (int j = 0; j < N; j++){
        int weight, value;
        cin >> weight >> value;
        for (int i = K; i >= 1; i--){
            if (i - weight >= 0) {
                dp[i] = max(dp[i], dp[i - weight] + value);
            }
        }
    }

    cout << dp[K];

    return 0;
}

