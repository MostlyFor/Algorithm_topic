#include <iostream>
#include <stack>
using namespace std;

int arr[100000];
int down[100000];
int dp[100000];


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]) down[i]=1;
    }
    
    dp[0] = down[0];
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1] + down[i];
    }
    // dp[i] = 0번에서 i번까지 연주했을 때 실수할 개수
    
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int st, ed; cin >> st >> ed;
        st--; ed--;
        cout << dp[ed] - dp[st] + down[st] - down[ed] << '\n';
    }
    return 0;
}