#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> p, int location) {
    int answer = 0;
    
    priority_queue<int> pq;
    
    int start = 0;
    
    for(int i=0; i<p.size(); i++){
        pq.push(p[i]);
    }
    
    while(p[location]!= -1){
        // 맨 위와 같을 때 까지 이동! 끝나면 start는 pq.pop()임
        while(p[start] != pq.top()){
            start++;
            if(start == p.size()) start = 0;
        }
        pq.pop();
        p[start] = -1;
        answer++;
    }
    
    return answer;
}