#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string translate(long long x){
    string s = "";
    
    while(x){
        if(x%2) s += "1";
        else s += "0";
        x /= 2; 
    }
    
    reverse(s.begin(), s.end());
    return s; 
}


// 포화 트리에서 0 밑에 1이 있으면 모순
// 
bool is_pos(string s, bool is_parent_zero){
    
    int n = s.size();
    int mid = n / 2;
    if(is_parent_zero && s[mid] == '1') return false;
    if(n == 1) return true;
    
    if(s[mid] == '0') is_parent_zero = true;
    
    
    return is_pos(s.substr(0, mid), is_parent_zero) && is_pos(s.substr(mid+1), is_parent_zero);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    

    
    // 10000개
    for(auto k : numbers){
        // k -> 이진수로 바꾸기
        string s = translate(k);
        // cout << s << '\n'; // test
    
        // 가능한 포화 길이 : 현재 길이에서 가장 인접한 포화
        int length = s.size();
        int bit_length = translate(length).size();
        int full = (1 << bit_length) - 1;
        // cout << full - length << '\n'; // test
        int cnt = full - length;
        while(cnt --) s = "0" + s;
        
        // 조건 : 0 밑에 1이 있으면 false;
        answer.push_back(is_pos(s, false));
        
        
    }
    return answer;
}