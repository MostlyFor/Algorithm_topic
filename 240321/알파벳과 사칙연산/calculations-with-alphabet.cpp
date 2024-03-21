#include <iostream>
#include <vector>

using namespace std;
int main() {
    string str; cin >> str;
    str= "+" + str;

    // 4 ^ 100? 이건 무조건 최적화 필요 ,,

    int ans = 0;
    for(auto ch : str){
        if(ch == '+') ans +=4;
        else if(ch == '*') ans *= 4;
        else if(ch == '-') ans-=1;
    }

    cout << ans; 
    return 0;

}