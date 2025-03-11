#include <iostream>
using namespace std;

int T;
int limit;

void f(int idx, string s, int res, int q){
    if(idx == limit+1){
        if(res+q== 0) cout << s << '\n';
        return;
    }
    
    if(q > 0) f(idx+1, s + ' ' + to_string(idx), res, q*10 + idx);
    else f(idx+1, s + ' ' + to_string(idx), res, q*10 - idx);
    
    f(idx+1, s + '+' + to_string(idx), res+q, idx);
    f(idx+1, s + '-' + to_string(idx), res+q, -idx);

    
}

int main(){
    cin >> T;
    
    while(T--){
        cin >> limit;
        f(2, "1", 0, 1);
        cout << '\n';
    }
    
    return 0;
}