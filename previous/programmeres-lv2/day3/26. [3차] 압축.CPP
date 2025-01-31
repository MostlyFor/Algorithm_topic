#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    
    //단어, 번호
    map<string,int> d;
    
    for(char i = 'A'; i<='Z'; i++){
        string tmp  ="";
        tmp+=i;
        d[tmp]=i-'A'+1;
    }
    
    
    //한 글자씩 넘어가면서 ㅏ전 등록
    int last = 27;
    for(int i=0; i<msg.size();i++){
        string tmp = "";
        tmp +=msg[i];
        //가장 긴 문자열 찾기 다음거가 없으면 멈춤
        
        while(i!=msg.size()-1 && d[tmp+msg[i+1]]!=0) tmp +=msg[++i];
        answer.push_back(d[tmp]);
        //새로운거 사전에 추가
        d[tmp+msg[i+1]] = last++;
        
    }
    
    return answer;
}