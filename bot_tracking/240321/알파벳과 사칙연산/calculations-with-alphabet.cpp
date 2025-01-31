#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(6,0);
int ans = -1e9;

string str;

int get_value(vector<int> arr){
    int tmp = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '+') tmp += arr[str[i+1]-'a'];
        else if(str[i] == '-') tmp -= arr[str[i+1]-'a'];
        else if(str[i] == '*') tmp *= arr[str[i+1]-'a'];
        else tmp /= arr[str[i+1]-'a'];
        i++;
    }


    return tmp;
}

int cnt =0;
void f(int idx){
    if(idx == 6){
        ans = max (ans, get_value(arr));
        return;
    }

    for(int i=1; i<=4; i++){
        arr[idx] = i;
        f(idx+1);
        arr[idx] = 0;
    }
}



int main() {
    cin >> str;
    str= "+" + str;

    f(0);

    cout << ans; 
    return 0;
}