#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult) {
    // 1. 점수 분리하기
    
    string tmp = "";
    vector<string> arr;
    
    for(auto ch : dartResult){
        if(0<= ch-'0' && ch-'0' <= 9 && tmp.size() >= 2){
            arr.push_back(tmp);
            tmp = "";
        }
        
        tmp += ch;
    }
    arr.push_back(tmp);
    
    // for(auto c : arr) cout << c << ' '; // test : 분리
    
    // 2. 점수 뒤에서부터 계산하기
    int ans = 0;
    bool x2 = false;
    bool x2_prev = false;
    bool x2_next = false;
    bool minus= false;
    for(int i=arr.size()-1; i>=0; i--){
        string cmd = arr[i];
        int score = 0;
        
        string tmp = "";
        for(auto k : cmd){
            if(k == '#') minus = true;
            if(k == '*') {
                x2 = true;
                x2_next = true;
            }
            
            if(k == 'S') score += stoi(tmp);
            if(k == 'D') score += stoi(tmp)*stoi(tmp);
            if(k == 'T') score += stoi(tmp)*stoi(tmp)*stoi(tmp);
            
            tmp += k;
        }
        
        if(minus) score *= -1;
        if(x2) score *= 2;
        if(x2_prev) score *= 2;
        
        ans += score;
        x2_prev = x2_next;
        minus = false;
        x2 = false;
        x2_next=false;
        // cout << ans << ' ';
    }
    
    return ans;
}