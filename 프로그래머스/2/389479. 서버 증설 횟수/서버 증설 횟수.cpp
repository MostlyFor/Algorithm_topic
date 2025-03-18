#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<int> server; // 서버 끝나는 시간
    
    for(int i=0; i<players.size(); i++){
        
        while(players[i] > (server.size()+1) * m -1){
            server.push(i+k-1);
            answer++;
        }
        
        // 이번 시간이 지나면 서버 끝남
        while(server.size() && server.front() == i){
            server.pop();
        }
    }
    
    return answer;
}