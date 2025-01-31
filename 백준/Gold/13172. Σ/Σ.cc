#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;

// a^(2n-1) % mod = (a^n % mod * a^(n-1) % mod) % mod
long long f(long long n, int x){
    if(x == 1) return n;
    if(x % 2 == 1) return f(n, x-1) * n % mod;
    
    long long res = f(n, x/2) % mod;
    return res * res % mod;
}

int main(){
    int m; cin >> m;
    
    long long ans = 0;
    
    for(int i=0; i<m; i++){
        long long a, b; cin >> b >> a;
        
        ans += a * f(b, mod-2);
        ans %= mod;
    }
    
    cout << ans;
    return 0;
}