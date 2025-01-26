#include <iostream>
using namespace std;
int x;
int main() {

    int q; cin >> q;

    for(int i=0; i<q; i++){
        string cmd; cin >> cmd;
        int a; cin >> a;

        if(cmd == "add") x = x | (1 << a);
        else if(cmd == "delete") x = x & ~(1 << a);
        else if(cmd == "print") cout << ((x & (1<<a)) ? 1 : 0)<< '\n';
        else if(cmd == "toggle") x = x ^ (1 << a);
        else x = 0;
    }

    return 0;
}