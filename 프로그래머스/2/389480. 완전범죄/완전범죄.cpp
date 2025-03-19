#include <string>
#include <vector>
#include <iostream>
using namespace std;
int state[9]; // 9가지 상태 저장
int answer = 1e9; // 끝까지 갔을 때 a의 최소 흔적
int limit_a, limit_b;

bool dp[10][121][121];



void f(int step, int a, int b){
    
    if(dp[step][a][b]) return;
    
    if(step == 9){
        if(a < limit_a && b < limit_b){
            answer = min(a, answer);
        }
        return;
    }
    
    for(int i=0; i<=state[step]; i++){
        if(a + i * (step/3 +1) >= limit_a) continue;
        if(b + (state[step] - i) * (step%3 + 1) >= limit_b) continue;
        f(step+1, a + i * (step/3 +1), b + (state[step] - i) * (step%3 + 1));
        dp[step+1][a + i * (step/3 +1)][b + (state[step] - i) * (step%3 + 1)] = true;
    }
}

int solution(vector<vector<int>> info, int n, int m) {
    limit_a = n;
    limit_b = m;
    
    for(auto x : info) state[(x[0]-1) * 3 + (x[1]-1)]++;
    
    f(0, 0, 0); // 완전탐색
    
    
    if(answer == 1e9 || answer >= limit_a) return -1;
    
    return answer;
}