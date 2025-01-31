#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<char,int> hmap;
    hmap['a'] = 1;
    hmap['e'] = 1;
    hmap['i'] = 1;
    hmap['o'] = 1;
    hmap['u'] = 1;

    string str = "";
    while (1) {
        cin >> str;
        if (str == "end") break;
        bool pos = true;
        // 1. 모음 하나 포함
        int cnt = 0;
        for (auto ch : str) cnt += hmap[ch];
        if (!cnt) pos = false;

        // 2. 모음 혹은 자음이 연속 3개면 안됨
        cnt = 1;
        int tmp = 1;
        for (int i = 0; i < str.size()-1; i++) {
            if (hmap[str[i]] == hmap[str[i + 1]]) tmp++;
            else tmp = 1;
            cnt = max(tmp, cnt);
        }
        if (cnt >= 3) pos = false;

        // 3. 같은 글자 연속 x, ee, oo는 허용
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == str[i + 1] && !(str[i] == 'e' || str[i] == 'o')) pos = false;
        }


        if (pos) cout << '<' << str << '>' << ' '<< "is acceptable." << '\n';
        if (!pos) cout << '<' << str << '>' <<' '<< "is not acceptable." <<'\n';
    }
    


    return 0;
}