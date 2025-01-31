#include <iostream>
using namespace std;

int main(){
    string arr[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    string str; cin >> str;
    string ans = "";
    auto tmp = stoi(arr[str[0] -'0']);
    ans += to_string(tmp);
    for(int i=1; i<str.size(); i++) ans += arr[str[i]-'0'];
    cout << ans;
}