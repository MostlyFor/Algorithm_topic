#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string num_to_str(long long x){
    string tmp = "";
    
    while(x){
        x--;
        tmp += ('a' + (x % 26));
        x /= 26;
    }

    string res = "";
    for(int i=tmp.size()-1; i>=0; i--) res += tmp[i];
    
    return res;
}

long long str_to_num(string str){
    long long x = 0;
    
    for(auto ch : str){
        x *= 26;
        x += 1 + (ch - 'a');
    }
    
    return x;
}

string solution(long long n, vector<string> bans) {
    
    vector<long long> bans_int;
    
    for(auto str: bans) bans_int.push_back(str_to_num(str));
    
    sort(bans_int.begin(), bans_int.end());
    
    int cnt = 0;
    for(int i=0; i<bans_int.size(); i++){
        if(n >= bans_int[i] - i) cnt++;
    }

    return num_to_str(n+cnt);
}