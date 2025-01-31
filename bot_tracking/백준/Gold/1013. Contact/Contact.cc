#include <iostream>
#include <vector>
using namespace std;

string str;
bool is_pos;
void init(){
    cin >> str;
}

bool pattern(int idx){
    if(str.size() == idx) return true;
    
    if(str[idx]=='0' && str[idx+1]=='1') return pattern(idx+2);
    
    if(str[idx] == '1' && str[idx+1] == '0' && str[idx+2] == '0'){
        int one_cnt = 0;
        idx += 3;
        
        while(idx < str.size() && str[idx]=='0') idx++; //0 끝날때까지
        while(idx < str.size() && str[idx]=='1') {idx++; one_cnt++;} // 1이 끝날때까지 진행

        if(one_cnt == 0) return false; // 1이 안나옴
        if(str.size() == idx) return true; // 마지막 패턴의 경우
        if(one_cnt ==1) return pattern(idx); // 다음 패턴이 01 확정
        return pattern(idx) || pattern(idx-1); // 01 또는 100+1+
    }
    else return false;
}

int main(){
    
    int T; cin >> T;
    
    while(T--){
        init();
        is_pos = pattern(0); // (100+1+)+ 패턴 맞는지 확인
        if(is_pos) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}