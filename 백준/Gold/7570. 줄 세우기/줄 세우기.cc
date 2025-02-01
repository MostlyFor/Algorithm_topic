#include <iostream>
using namespace std;

int n;
int arr[1000001];
int dp[1000001];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        dp[arr[i]] = dp[arr[i]-1] + 1;
        ans = max(dp[arr[i]], ans);
    }
    
     cout << ((ans == 0) ? n-1 : n - ans) << '\n';
    
    return 0;
}