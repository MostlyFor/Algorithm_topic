#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // 야근 피로도 최소화
    
    // 매 시간마다 가장 큰 놈 줄이는 방식이나, 아니면 그리디하게 아예 수학으로 풀 수 있을 것 같은데 구현이 쉬운 우선순위 큐 사용.
    // 가장 쉬운 구현, O(NlogM+MlogM)
    // 조금 더 나은 구현은 정렬 후 1등과 2등 만큼 2등 줄이기 
    
    for(auto w : works) pq.push(w);
    
    while(n--){
        int h = pq.top(); pq.pop();
        h--; 
        pq.push(h);
    }
    
    while(pq.size()){
        int k = pq.top(); pq.pop();
        if(k < 0) continue;
        long long tmp = 1;
        answer += tmp * k * k;
    }
    
    return answer;
}