#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int cnt = 0;
    for(int i=a; i<=b; i++){
        int n = i;

        string tmp2 = to_string(n);
        string tmp = tmp2;
        reverse(tmp.begin(), tmp.end());
        if(tmp == tmp2) cnt++;
    }
    cout << cnt;

    return 0;
}