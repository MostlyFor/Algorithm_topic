#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    //대기 목록에서 중요도 최댓값을 만들자.
    queue<int> q;
    unordered_map<int,int> m;
    
    
    for(auto p : priorities){
        m[p]++;
        q.push(p);
    }
   
    while(!q.empty()){
        bool pass = false;
        // 가장 큰 값 존재 -> 대기목록 마지막으로 미룸
        for(int i=9; i>q.front(); i--){
            if(m[i]>0) {
                q.push(q.front());
                q.pop();
                //location 좌표 구하는데 좀걸리네..
                location--;
                if(location<0) location+=q.size();
                pass = true;
            }
            if(pass) break;
        }
        if(pass) continue;
        //내가 가장 큰 값이면 그냥 나옴
        m[q.front()] --;
        q.pop();
        answer++;
        if(location==0) return answer;
        location--;
        if(location<0) location+=q.size();
    }
    
    
    
    return answer;
}