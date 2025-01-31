#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 43 4 37 43437
// 44337
// 하나 숫자가 있을 때 이게 더 optimal은 아니고 44 이상이어야 optimal
// 443 4
// 숫자 비교할 땐 자릿수 맞춰주고 같은 숫자로 맞춘다음 해야 함
int main() {
    int n; cin >> n;
    vector<pair<string, int>> arr;
    for(int i=0; i<n; i++){
        int k; cin >> k;
        string tmp = to_string(k);
        int num = tmp.size();
        while(tmp.size() != 10){
            tmp = tmp + tmp[tmp.size()-1];
        }
        arr.push_back({tmp, num});
    }

    sort(arr.begin(), arr.end(), greater<>());


    string longest = "";
    
    for(auto k : arr){
        string tmp = k.first;
        int len  = k.second;

        longest += tmp.substr(0, len);
    }

    cout << longest;
    return 0;
}