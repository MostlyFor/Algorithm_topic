#include <iostream>
using namespace std;

int dp[1001][3][3];
int arr[1001][3]; // 색칠 비용 정보

int main(){
    int n; cin >> n;
    
    // 모든 경우의 수를 나열할 수 있지만, i 번째로 오기까지의 과정이 어떻든 해당 비용이 최소인게 중요함 
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
            for(int k=0; k<3; k++)
            dp[i][j][k] = 1e9;
        }
    }
    
    
    // 1. a로 시작하는 경우
    dp[1][0][0] = arr[1][0]; // 0 시작
    dp[1][1][1] = arr[1][1]; // 1 시작
    dp[1][2][2] = arr[1][2]; // 2 시작
    
    for(int i=2; i<=n; i++){
        for(int k=0; k<3; k++){
            dp[i][0][k] = min(dp[i-1][1][k] + arr[i][0], dp[i-1][2][k] + arr[i][0]);
            dp[i][1][k] = min(dp[i-1][0][k] + arr[i][1], dp[i-1][2][k] + arr[i][1]);
            dp[i][2][k] = min(dp[i-1][0][k] + arr[i][2], dp[i-1][1][k] + arr[i][2]);
        }
    }
    
    int answer = 1e9;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j) continue;
            answer = min(answer, dp[n][i][j]);
        }
    }
    cout << answer;
    
    return 0;
}