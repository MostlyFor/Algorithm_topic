#include <iostream>
using namespace std;

int dp[1001][3];
int dp1[1001][3];
int dp2[1001][3];
int arr[1001][3]; // 색칠 비용 정보

int main(){
    int n; cin >> n;
    
    // 모든 경우의 수를 나열할 수 있지만, i 번째로 오기까지의 과정이 어떻든 해당 비용이 최소인게 중요함 
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
            dp[i][j] = 1e9;
            dp1[i][j] = 1e9;
            dp2[i][j] = 1e9;
        }
    }
    
    
    // 1. a로 시작하는 경우
    dp[1][0] = arr[1][0];
    for(int i=2; i<=n; i++){
        dp[i][0] = min(dp[i-1][1] + arr[i][0], dp[i-1][2] + arr[i][0]);
        dp[i][1] = min(dp[i-1][0] + arr[i][1], dp[i-1][2] + arr[i][1]);
        dp[i][2] = min(dp[i-1][0] + arr[i][2], dp[i-1][1] + arr[i][2]);
    }
    
    dp1[1][1] = arr[1][1];
    for(int i=2; i<=n; i++){
        dp1[i][0] = min(dp1[i-1][1] + arr[i][0], dp1[i-1][2] + arr[i][0]);
        dp1[i][1] = min(dp1[i-1][0] + arr[i][1], dp1[i-1][2] + arr[i][1]);
        dp1[i][2] = min(dp1[i-1][0] + arr[i][2], dp1[i-1][1] + arr[i][2]);
    }
    
    dp2[1][2] = arr[1][2];
    for(int i=2; i<=n; i++){
        dp2[i][0] = min(dp2[i-1][1] + arr[i][0], dp2[i-1][2] + arr[i][0]);
        dp2[i][1] = min(dp2[i-1][0] + arr[i][1], dp2[i-1][2] + arr[i][1]);
        dp2[i][2] = min(dp2[i-1][0] + arr[i][2], dp2[i-1][1] + arr[i][2]);
    }
    
    
    int answer = min(dp[n][1], min(min(dp[n][2], dp1[n][0]), min(dp1[n][2], min(dp2[n][0], dp2[n][1]))));
    cout << answer;
    
    return 0;
}