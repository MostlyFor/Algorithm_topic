#include <iostream>
#include <climits>
using namespace std;

long long arr1[501];
long long arr2[501];

long long dp[501][501]; // i, j까지 연산했을 때의 최소 비용 

int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr1[i];
        cin >> arr2[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            dp[i][j] = 3e10;
        }
    }
    
    for(int len = 1; len <= n-1; len++){
        for(int i=0; i+len<n; i++){
            int j = i+len;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr1[i] * arr2[k] * arr2[j], dp[i][j]);
            }
        }
    }

    cout << dp[0][n-1];
    return 0;
}