#include <iostream>
#include <set>
#include <string>
using namespace std;

struct cmp {
    bool operator() (const string& s1, const string& s2) const {
        if (s1.size() < s2.size()) return true;
        else if (s1.size() == s2.size() && s1 < s2) return true;
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    set<string, cmp> arr;
    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        arr.insert(tmp);
    }

    for (const auto& s : arr) {
        cout << s << '\n';
    }

    return 0;
}