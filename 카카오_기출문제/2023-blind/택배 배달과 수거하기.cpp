#include <string>
#include <vector>
#include <stack>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    // 시작할 때 배달은 항상 풀로 채워서 가기
    stack<pair<int,int>> st_d; // 배달 {개수, 인덱스}
    stack<pair<int,int>> st_p; // 픽업
    
    for(int i=0; i<n; i++){
        if(deliveries[i]) st_d.push({deliveries[i], i});
        if(pickups[i]) st_p.push({pickups[i], i});
    }
    
    while(st_d.size() || st_p.size()){
        int b = 0;
        int d = 0;
        if(st_d.size()) b = st_d.top().second;
        if(st_p.size()) d = st_p.top().second;
        
        answer += 2 * (max(b, d) + 1);
        
        // 각각 cap 개씩 빼기
        int left_d = cap;
        while(st_d.size() && left_d){
            st_d.top().first -= left_d;
            left_d = 0;
            if(st_d.top().first <= 0){
                left_d = -st_d.top().first;
                st_d.pop();
            }
        }
        
        int left_p = cap;
        while(st_p.size() && left_p){
            st_p.top().first -= left_p;
            left_p = 0;
            if(st_p.top().first <= 0){
                left_p = -st_p.top().first;
                st_p.pop();
            }
        }
    }
    
    return answer;
}