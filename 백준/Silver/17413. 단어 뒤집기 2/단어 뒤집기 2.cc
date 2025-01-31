#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>

using namespace std;

// 시간복잡도 O()


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin , s);
    s += " ";

    vector<string> ans;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {

        // 공백 발견 -> 이전까지의 string 단어 취급
        if (s[i] == ' ') {
            ans.push_back(tmp);
            tmp = "";
            continue;
        }
        
        // 태그 발견 -> 이전까지의 string 단어 취급 + 이후 태그까지 이동
        if (s[i] == '<') {
            if (tmp != "")
                ans.push_back(tmp);

            tmp = "";
            while (s[i] != '>') {
                tmp += s[i];
                i++;
            }
            tmp += ">";
            ans.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += s[i];
    }

    for (int j = 0; j < ans.size(); j++) {
        string str = ans[j];
        if (str[0] != '<') {
            for (int i = str.size()-1; i >= 0; i--) cout << str[i];

            if (j + 1 == ans.size()) continue;
            if (ans[j + 1][0] != '<') cout << ' ';
        }
        else
            for (auto ch : str) cout << ch;

    }
    
    return 0;
}