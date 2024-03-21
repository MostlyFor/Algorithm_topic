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
    for(int i=arr.size()-1; i>=0; i--){
        cnt += k / arr[i];
        k = k%  arr[i];
    }

    cout << cnt;
    return 0;
}