#include <iostream>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    int ans = 0;
    for(int i=a; i<=b; i++){
        int n = i;
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n/=10;
        }
        ans = max(ans ,sum);
    }
    cout << ans;
    return 0;
}