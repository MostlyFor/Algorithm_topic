#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
     if(k>=enemy.size()) return enemy.size();
    
    
    int index = 0;
    while(k--) pq.push(enemy[index++]);
    
    
   
    
    //index는 다음에 들어갈 곳을 가리킴
    // 다음 라운드에 갈 수 없다면 끝내
    while(index!=enemy.size()){
        pq.push(enemy[index]);
        if(pq.top() > n) break; //해당 index까지 못감
        n -= pq.top(); pq.pop();
        index ++;
    }
    
    
    return index;
}