#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
vector<int> failure;
vector<int> ans;
int before = 0;

void get_failure(string s){
    failure.resize(s.size(), 0);
    
    // failure[i] 채우기
    failure[0] = 0;
    for(int i=1; i<(int)s.size(); i++){
        int x = failure[i-1];
        while(1) {
            if(s[i] == s[x]) {
                failure[i] = x+1;
                break;
            }
            
            if(x==0) break;
            
            x = failure[x-1];
        }
    }
}

// 겹치는 패턴값 반환
int KMP(int st, int st2){
    
    int j = st2;
    for(int i=st; i<(int)T.size(); i++){
        
        if(j == (int)P.size()) return i - j+1;
        
        // 문자가 같은 경우
        if(T[i] == P[j]) {
            j++;
            continue;
        }
        
        // 문자가 틀린 경우
        if(j == 0) 
            continue;
        
        j = failure[j-1];
        while(1){
            if(T[i] == P[j]) {
                j++;
                break;
            }
            if(j == 0) break;
            j = failure[j-1];
        }
    }
    
    if(j == (int)P.size()) return (int)T.size() - (int)P.size()+1;
    return 0;
}

int main(){
    
    getline(cin, T);
    getline(cin, P);

    get_failure(P);
    
    int res = KMP(0, 0);

    while(res){
        ans.push_back(res);
        before = res-1;
        res = KMP(before + (int)P.size(), failure[(int)P.size()-1]);
    }
    
    
    cout << ans.size() << '\n';
    for(auto k : ans) cout << k << ' ';
    
    return 0;
}