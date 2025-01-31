#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 목표는 모든 음식의 지수를 K이상
    // 가장 낮은 애 2개 골라서 해야함.
    
    priority_queue<int> pq;
    for(auto i : scoville) pq.push(-i);
    
    while(!pq.empty() && -pq.top()<K){
        int s1 = -pq.top(); pq.pop();
        if(pq.empty()) return -1;
        int s2 = -pq.top(); pq.pop();
        
        pq.push(-s1 - 2*s2);
        answer++;
    }
    
    if(pq.empty()) return -1;
    
    return answer;
}