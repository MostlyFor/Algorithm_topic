#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int answer = 0;
int cnt = 0;
set<int> st;


bool is_prime(int n){
    if(n==1) return false;
    if(n==0) return false;
    
    for(int i=2;i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void dfs(string s,string tmp,int depth){
 
    
    if(tmp !="")
        st.insert(stoi(tmp));
    
    if(depth == s.size()) return;
    
    
    for(int i=depth; i<s.size();i++){
        swap(s[depth],s[i]);
        dfs(s,tmp+s[depth],depth+1);
        swap(s[i], s[depth]);
    }
    
    return;
}


int solution(string numbers) {
    
    string tmp = "";
    
    dfs(numbers,tmp,0);
    
    for(auto it : st)
        if(is_prime(it)) answer++;
    
    return answer;
}