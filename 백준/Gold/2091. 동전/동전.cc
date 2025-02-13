#include <iostream>
#include <vector>
using namespace std;

int dp[10001]; // dp[i] : i원을 만드는데 필요한 최대 동전 수
vector<vector<int>> used(10001, vector<int>(4,0));

int main(){
    int x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    
    int coins[4] = {1, 5, 10, 25};
    int have[4] = {a,b,c,d};
    
    dp[0] = 1;
    
    for(int i = 0; i<4; i++){
        for(int j=coins[i]; j<=x; j++){
            if(dp[j-coins[i]] == 0) continue; // 만들 수 없는 경우
            if(used[j-coins[i]][i] == have[i]) continue;
            if(dp[j-coins[i]] + 1 > dp[j]){
                dp[j] = dp[j-coins[i]]+1;
                
                for(int k=0; k<4; k++) used[j][k] = used[j-coins[i]][k];
                
                used[j][i] = used[j-coins[i]][i] +1;
            }
        }
    }
    
    
    for(auto k : used[x]) cout << k << ' ';
    
    return 0;
}