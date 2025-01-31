#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day = 1;
    
    
    for(int i=0; i<progresses.size();i){
        int cnt = 0;
        while(progresses[i] + day*speeds[i] < 100) day++;
        //while문 끝나면 i번째 날 진도 완료
        
        //작업 완료한 애들 추가
        while(progresses[i]+day*speeds[i] >= 100 && i<progresses.size()){
            cnt++; i++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}