#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long limit = 9876543210;
vector<long long> arr;

void f(int idx, long long now){
    arr.push_back(now);
    
    for(int i=0; i<idx; i++){
        f(i, now*10 + i);
    }
}

void solve(){
    for(int i=1; i<=9; i++) f(i, i);
    sort(arr.begin(), arr.end());
}

int main(){
    
    solve();
    
    cin >> n;
    if(n == 0) cout << 0 << '\n';
    else if(arr.size() <= n-1) cout << -1;
    else cout << arr[n-1];
    return 0;
}