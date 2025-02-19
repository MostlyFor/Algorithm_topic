#include <iostream>
using namespace std;

int dp[4001][4001];

int main(){
    string s1, s2; cin >> s1 >> s2;

    int ans = 0;
    
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            char ch1 = s1[i];
            char ch2 = s2[j];
            if(ch1 == ch2) dp[i+1][j+1] = dp[i][j] + 1;
            ans = max(dp[i+1][j+1], ans);
        }
    }

    cout << ans;
    
    return 0;
}