#include <iostream>
#include <vector>
using namespace std;


int n, k;
vector<int> arr;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    int cnt = 0;
    int idx = arr.size()-1;
    while(k!=0){
        if(arr[idx] <= k){k-= arr[idx]; cnt++;}
        else idx--;
    }

    cout << cnt;
    return 0;
}