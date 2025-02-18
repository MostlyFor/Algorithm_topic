#include <iostream>
using namespace std;
int arr[5000];
int dp[5000][5000]; // s[l:r+1]까지 몇 개의 문자가 필요한지?


int f(int l, int r){
    if(l > r) return 1e9;
    if(dp[l][r] != 1e9) return dp[l][r];
    if(l==r) return dp[l][r] = 0;
    if(l+1 == r){
        if(arr[l] == arr[r]) return dp[l][r] = 0;
        else return dp[l][r] = 1;
    }
    
    
    if(arr[l] == arr[r]) return dp[l][r] = f(l+1, r-1);
    
    return dp[l][r] = min(f(l+1,r), f(l,r-1)) + 1;
    // dp[i][j] = min(dp[i+1][j]+1, dp[i][j-1]+1);
}


int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 1e9;
        }
    }
    
    cout << f(0, n-1);
    
    return 0;
}