#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        arr.push_back({b,a});
    }

    sort(arr.begin(), arr.end());


    int ans = 0;
    int last = 0;
    for(int i=0; i<n; i++){
        
        // 회의를 시작할 수 있으면 시작
        if(last <= arr[i].second) {
            ans++;
            last = arr[i].first;

        }
    }

    cout << ans;
    return 0;
}