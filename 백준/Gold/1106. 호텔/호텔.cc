#include <iostream>
using namespace std;

int dp[1101]; // dp[x] = 인원을 x명까지 늘리는데 드는 최소 비용, 단, x명에 딱 맞춰지지 않을 수 있으므로 최대 차이 100 여분

int main(){
    int n, k; cin >> n >> k;
    
    for(int i=1; i<=n+100; i++) dp[i] = 1e9;
    
    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b; // a원 써서 b명 늘어남
        for(int j=b; j <= n+100; j++){
            dp[j] = min(dp[j], dp[j - b] + a);
        }
    }
    
    for(int i=0; i<=100; i++){
        dp[n] = min(dp[n], dp[n+i]);
    }
    cout << dp[n];
    
    return 0;
}