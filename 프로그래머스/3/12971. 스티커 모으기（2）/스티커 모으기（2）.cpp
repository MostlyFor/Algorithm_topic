#include <iostream>
#include <vector>
using namespace std;


vector<int> sticker;

int sol(int st, int ed){

    int dp[100000][2];
    for (int i = 0; i < 100000; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    
    dp[st][1] = sticker[st];
    dp[st][0] = 0;
    
    for(int i=st+1; i<ed; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = dp[i-1][0] + sticker[i];
    }
    
    return max(dp[ed-1][0], dp[ed-1][1]);
}

int solution(vector<int> s)
{
    sticker = s;
    int n = sticker.size();
    if(n == 1) return sticker[0];

    // 스티커 뜯어서 얻을 수 있는 최대 값
    

    int answer = 0;
    answer = max(answer, sol(2, n-1) + sticker[0]); // 왼쪽 끝 뜯은 경우
    answer = max(answer, sol(1, n-2) + sticker[n-1] ); // 오른쪽 끝 뜯은 경우
    answer = max(answer, sol(1, n-1)); // 둘 다 보존
    
    return answer;
}