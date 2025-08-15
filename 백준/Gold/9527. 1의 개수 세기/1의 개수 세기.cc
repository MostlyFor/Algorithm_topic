#include <iostream>
using namespace std;
long long a, b;

long long f(long long b){
    long long ans = 0;
    long long x = 1;
    while(x <= b){
        // x 번째 비트가 언제 활성화 되는지?
        ans += (b - x+1) / (2*x) * x + min(x , (b - x+1) % (2*x));
        x = x << 1;
    }
    
    return ans;
}

int main(){
    cin >> a >> b;
    
    
    cout << f(b) - f(a-1) << '\n';
    
    return 0;
}