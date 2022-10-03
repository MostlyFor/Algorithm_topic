#include <iostream>
#include <cmath>
using namespace std;

int ans;

int f(int n, int r, int c){
    if(n==1) return ans;
    
    n/=2;
    
    if(r<n && c<n) return f(n,r,c);
    else if(r<n && c>=n){
        ans += n*n;
        return f(n,r,c-n);
    }
    else if(r>=n && c<n){
        ans += 2*n*n;
        return f(n,r-n,c);
    }
    else {
        ans += 3*n*n;
        return f(n,r-n,c-n);
    }
}


int main(){
    int n,r,c;
    ans = 0;
    
    cin >> n >> r >> c;
    n = pow(2,n);
    
    cout << f(n,r,c);
    return 0;
}