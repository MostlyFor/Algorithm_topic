#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


// 시간복잡도 : O() : 
// 공간복잡도 : O() :
int stack[10001];
int last = 0;

void push(int x) {
    stack[last] = x;
    last++;
}

void pop() {
    if (last == 0) cout << -1 << '\n';
    else {
        cout << stack[last-1] << '\n';
        last--;
    }
}

void top() {
    if (last == 0) cout << -1 << '\n';
    else cout << stack[last-1] << '\n';
}

void empty() {
    cout << (last == 0) ? 1 : 0;
    cout << '\n';
}

void size() {
    cout << last << '\n';
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if (str[0] == 'p' && str[1] == 'u') push(stoi(str.substr(5)));
        else if (str[0] == 'p' && str[1] == 'o') pop();
        else if (str[0] == 't') top();
        else if (str[0] == 'e') empty();
        else if (str[0] == 's') size();
    }

    return 0;
}

