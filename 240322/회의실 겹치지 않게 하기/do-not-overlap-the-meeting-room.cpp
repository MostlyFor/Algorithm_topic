#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> arr;


bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    else if(p1.second == p2.second && p1.first > p2.first) return true;
    return false;
}



int main() {
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        arr.push_back({a,b});
    }

    sort(arr.begin(), arr.end(), cmp);

    int last = 0;
    int ans =0;

    for(auto p : arr){
        int st = p.first;
        int ed = p.second;
        if(last <= st){
            last = ed;
            ans++;
        }
    }

    cout << n - ans;
    return 0;
}