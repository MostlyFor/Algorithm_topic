#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


// x를 n 진법으로 바꾸는 함수
string get_transformed(int x, int n){
    if(x == 0) return "0";
    string s = "";
    
    while(x){
        int rest = x % n ;
        if(rest >= 10) s += 'A' + (rest-10);
        else s += to_string(rest);
        x /= n;
    }
    
    reverse(s.begin(), s.end());
    return s;
}

string solution(int n, int t, int m, int p) {
    string total = "";
    // 수를 변환하는게 첫 번째 과제. 많아야 10만개
    
    int i=0;
    while(total.size() < t * m){
        total += get_transformed(i++, n);
    }
    
    // cout << total << '\n';
    string answer = "";
    for(int i=0; i<t; i++){
        answer += total[i * m + p - 1];
    }
    return answer;
}