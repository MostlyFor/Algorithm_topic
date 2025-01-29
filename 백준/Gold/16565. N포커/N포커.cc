#include <iostream>
using namespace std;

int dp[53][53]; // dp[n][k] : n장에서 k개를 뽑을 때 포카드를 만드는 경우의 수
int comb[53][53];

int main(){
    int n; cin >> n;

    for(int i=0; i<=52; i++){
        for(int j=0; j<=i; j++){
            if(j == 0) {comb[i][j] = 1; continue;}
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % 10007;
        }
    }

    for(int i=4; i<=52; i+=4){
        for(int j=4; j<=i; j++){
            if(i == j) dp[i][j] = 1;
            else{
                int fc = i / 4; // 포카드 묶음 수
                for(int k=1; k<=j/4; k++){ // k : 만드려고 하는 포카드 수
                    // k 개의 포카드 만든 후, i - 4*k에서 포카드 없이 j - 4*k개 제거
                    int a = 4 * (fc - k); // 현재 남은 덱 수
                    int b = j - 4 * k; // 현재 남은 뽑을 수
                    dp[i][j] = (dp[i][j] + (comb[fc][k] * ( (comb[a][b] - dp[a][b] + 10007)%10007 )) % 10007) % 10007;
                }
            }
        }
    }

    cout << dp[52][n];
    return 0;
}
