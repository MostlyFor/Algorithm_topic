#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> arr;
priority_queue <pair<int,int>> pq;
int ans = 0;

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        arr.push_back({b,a});
    }
    int d; cin >> d;
    
    sort(arr.begin(), arr.end());
    

    int idx = 0;
    
    while(idx != arr.size()){
        
        // 1. 새로운 구간 범위 설정
        int ed = arr[idx].first;
        int st = ed - d;

        
        // 2. 새로운 구간에서 탈락하는 애들 확인
        while(pq.size()){
            int _st = -pq.top().first;
            int _ed = pq.top().second;
            
            if(_st < st) pq.pop();
            else break;
        }

        
        // 3. 새로운 구간에 편입되는 애들 확인
        while(idx != arr.size() && arr[idx].first <= ed){
            if(st <= arr[idx].second) pq.push({-arr[idx].second, arr[idx].first});
            idx++;
        }
        
        ans = max(ans, (int)pq.size());

    }
    
    cout << ans;
    
    return 0;
}