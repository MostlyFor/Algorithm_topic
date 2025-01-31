#include <iostream>
#include <vector>
using namespace std;

int k, n;
void f(vector<int> arr){
    if(arr.size() == n){
        for(auto x : arr) cout << x << ' ';
        cout << '\n';
        return;
    }


    for(int i=1; i<=k; i++){
        arr.push_back(i);
        f(arr);
        arr.pop_back();
    }
}


int main() {
   
    cin >> k >> n;
    vector<int> tmp;
    f(tmp);
    return 0;
}