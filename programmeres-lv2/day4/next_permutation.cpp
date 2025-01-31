#include <string>
#include <vector>
#include <iostream>
using namespace std;

void s(vector<int> v, vector<int> tmp, int a) {
    if (tmp.size() == v.size()) {
        for (auto k : tmp)
            cout << k << ' ';
        cout << '\n';
        return;
    }
    for (int i = a; i < v.size(); i++) {
        tmp.push_back(v[i]);
        swap(v[i], v[a]);
        s(v, tmp,a+1);
        swap(v[i], v[a]);
        tmp.pop_back();
    }
}

int main() {

    vector<int> v= { 1,2,3,4 };
    vector<int> tmp;
    s(v,tmp,0);
    return 0;
}