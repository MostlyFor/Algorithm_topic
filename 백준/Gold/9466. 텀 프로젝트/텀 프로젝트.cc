#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int,int> visit; // 이전 사이클에 방문했던 노드
unordered_map<int,int> is_in_cycle; // 사이클인지?
int pointer[100001];

void f(int st, vector<int>& arr, unordered_map<int,int>& tmp){
    arr.push_back(st);
    if(visit.find(st) != visit.end()) return; // 함수의 종료 조건 2. 이전에 방문했었던 노드
    if(is_in_cycle.find(st) != is_in_cycle.end()) return; // 함수의 종료 조건 1. 사이클 탐지
    tmp[st]++;
    if(tmp[st] == 2) is_in_cycle[st]++;
    f(pointer[st], arr, tmp);
}


void solve(){
    cin >> n;
    is_in_cycle.clear();
    visit.clear();
    for(int i=1; i<=n; i++) cin >> pointer[i];
    
    for(int i=1; i<=n; i++){
        if(visit.find(i) != visit.end()) continue;
        vector<int> arr; // 이번 사이클에 들어가는 노드
        unordered_map<int,int> tmp;
        f(i, arr, tmp);
        for(auto k : arr) visit[k]++;
    }

    cout << n - is_in_cycle.size() << '\n';

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}