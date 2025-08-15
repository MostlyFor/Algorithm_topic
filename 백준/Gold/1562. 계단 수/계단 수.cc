#include <iostream>
using namespace std;


long long dp[10][101][1<<10]; // dp[k][l][state] : k로 끝나고 길이가 l이며 쓰인 수가 state인 계단 수

int main(){
    int n; cin >> n;
    
    for(int k=1; k<10; k++){
        dp[k][1][1<<k] = 1;
    }
    
    // dp[k][l][state]를 업데이트 하는 것
    // 업데이트 조건 : 이전 상태에서 추가했을 때 k, l, state가 될 수 있는가?
    for(int l=2; l<=n; l++){
        for(int k=0; k<10; k++){
            for(int state=0; state < (1<< 10); state++){
                if((state & (1 << k)) == 0) continue;
                int pstate = state & ~(1<<k);
                if(k == 0) dp[k][l][state] += dp[k+1][l-1][state] + dp[k+1][l-1][pstate];
                else if(k == 9) dp[k][l][state] += dp[k-1][l-1][state] + dp[k-1][l-1][pstate];
                else dp[k][l][state] += dp[k+1][l-1][state] + dp[k+1][l-1][pstate] + dp[k-1][l-1][state] + dp[k-1][l-1][pstate];
                
                dp[k][l][state] %= 1000000000;
            }
        }
    }
    
    
    long long ans = 0;
    for(int i=0; i<10; i++){
        ans += dp[i][n][(1<<10) -1];
    }
    
    cout << ans % 1000000000 << '\n';
    
    return 0;
}