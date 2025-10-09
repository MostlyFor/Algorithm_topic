#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 1e9;

// 문자열 s에 대해 길이 p_len 짜리 pattern 탐지 후 압축
void replace_pattern(string s, int p_len){
    
    int len = s.size();
    for(int i=0; i<s.size(); i+= p_len){
        // 패턴 인식 못하면 아웃
        if(i + p_len >= s.size()) break;
        string pattern = s.substr(i, p_len);
        // cout << p_len << ' ' << pattern << '\n';
        
        int cnt = 1;

        // 해당 패턴이 몇개인지 파악 (cnt 개수만큼)
        while(i+ (cnt+1) * p_len -1 < s.size()){
            string candidate = s.substr(i + p_len*cnt, p_len);
            if(pattern != candidate) break;
            else cnt++;
        }

        if(cnt > 1){
            // cout << pattern << ' ' << cnt << '\n';
            len -= (cnt - 1) * p_len;
            len += (cnt / 1000 > 0)  + (cnt / 100 > 0) + (cnt / 10 > 0) + 1;
            i = i + p_len *(cnt) -p_len ;
        }
    }
    
    answer = min(answer, len);
}

int solution(string s) {
    for(int p_len =1; p_len<501; p_len++){
        replace_pattern(s, p_len);
    }
    
    return answer;
}

