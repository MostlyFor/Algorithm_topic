#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    map<int,int> m;

    for(auto l : lost)
        m[l] = 1;
    
    
    // 여벌 체육복 도난 당한 친구
    for(int i=0; i<reserve.size(); i++)
        if(m[reserve[i]]!=0){
            m[reserve[i]] = 0;
            reserve[i] =-1;
            answer++;
        }
    
    
    sort(reserve.begin(),reserve.end());
    
    for(int i=0; i<reserve.size(); i++){
        
        if(reserve[i]==-1) continue;
        
       
        if(m[reserve[i]-1]!=0){
            answer++;
            m[reserve[i]-1]=0;
            continue;
        }
        // 체육복 자신보다 높은 친구한테 빌려줄 수 있으면 빌려주기
        else if (m[reserve[i]+1]!=0){
            answer++;
            m[reserve[i]+1] = 0;
            continue;
        }
    }
    
    
    return n - lost.size() + answer;
}