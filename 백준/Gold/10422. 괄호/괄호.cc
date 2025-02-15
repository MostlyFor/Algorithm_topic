#include <iostream>
using namespace std;

long long dp[5001];

int main(){
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<5001; i++){
        for(int j=0; j <= i-1; j++){
            dp[i] += dp[j] * dp[i-1-j];
            dp[i] %= 1000000007;
        }
    }
    
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2) cout << 0 << '\n';
        else cout << dp[n/2] << '\n';
    }
    
    return 0;
}

