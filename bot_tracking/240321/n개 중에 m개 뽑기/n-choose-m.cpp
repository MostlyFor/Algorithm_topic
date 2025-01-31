#include <iostream>
#include <vector>
using namespace std;

int n, m;

void f(vector<int> arr, int idx){
    if(arr.size()==m){
        for(auto k : arr) cout << k << ' ';
        cout << '\n';
        return;
    }


    for(int i=idx; i<=n;i++){
        arr.push_back(i);
        f(arr,i+1);
        arr.pop_back();
    }
}

int main() {
    cin >> n >> m;

    vector<int> arr;
    f(arr, 1);
    return 0;
}