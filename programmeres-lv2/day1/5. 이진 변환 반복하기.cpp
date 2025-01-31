#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    string tmp;
    
    while(s!="1"){
        // 1. 0 개수 세고 answer에 저장하기
        int zero_count = 0;
        for(auto st : s)
            if(st == '0') zero_count++;
        answer[1] += zero_count;
        
        int len = s.size()-zero_count;
            
        // 2. 2진 변환
        // 2 = 2 x 1 + 0 
        // 3 = 2 x 1 + 1 
        // 4 = 2 x 2 + 0 -> 1 0 0
        while(len!=0){
            int b = len%2;
            len /=2;
            // 나머지 있으면 맨 뒤에 추가
            tmp.push_back('0'+b);
        }
        reverse(tmp.begin(),tmp.end());
        s = tmp;
        tmp.clear();
        answer[0] +=1;
    }
    
    return answer;
}