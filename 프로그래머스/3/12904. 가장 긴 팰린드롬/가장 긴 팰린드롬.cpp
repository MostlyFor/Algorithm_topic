#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;

int pal(string s, int l, int r){
    
    while(0<= l && r < n && s[l] == s[r]){
        l--; r++;
    }
        
    l++; r--;
    
    return r-l+1;
}

int solution(string s)
{
    // 길이가 3, 2짜리인 펠린드롬에서 확장
    n = s.size();
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        ans = max(ans, pal(s,i,i));
        ans = max(ans, pal(s,i,i+1));
    }

    
    return ans;
}