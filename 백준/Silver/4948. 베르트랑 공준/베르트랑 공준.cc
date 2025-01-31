#include <iostream>
using namespace std;

bool is_not_prime[250001];
int dp[250001];

int main(){
    
    is_not_prime[0] = 1;
    is_not_prime[1] = 1;
    
    for(int i=2; i * i<=250000; i++){
        
        if(is_not_prime[i]) continue;
        
        for(int j = i*i; j <=250000; j += i){
            is_not_prime[j] = true;
        }
    }
    
    
    // dp[i] : i를 포함, i 보다 작은 수들 중 소수의 수
    for(int i=2; i<=250000 ;i++){
        dp[i] = dp[i-1] + (!is_not_prime[i]);
    }
    
    int x; 
    cin >> x;
    while(x){
        cout << dp[2 * x] - dp[x] << '\n';
        cin >> x;
    }
    
    return 0;
}