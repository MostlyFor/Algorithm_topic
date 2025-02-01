#include <iostream>
#include <string>
using namespace std;

bool is_not_prime[1000001];
int dp[1000][1000];

int main(){
    
    for(int i=2; i*i<=1000000; i++){
        if(is_not_prime[i]) continue;
        for(int j=i*i; j <=1000000; j += i) is_not_prime[j] = true;
    }
    
    int n; cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])+ !is_not_prime[stoi(to_string(i) + to_string(j))];
        }
    }
    
    cout << dp[n][n] - 1;
    
    return 0;
}