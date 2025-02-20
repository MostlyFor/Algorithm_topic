#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,int>> pq;


int main(){
    
    int m; cin >> m;
    
    int st = 0;
    int a = 1;
    int b = 1;
    int ans =0;
    int longest = -1e9;
    
    while(a!=0 || b!=0){
        cin >> a >> b;
        pq.push({-a, b});
    }

    while(pq.size()){
        auto h = pq.top();pq.pop();
        int a = -h.first;
        int b = h.second;
        
                
        // 현재 갈 수 있는 최대 길이
        if(a <= st) longest = max(longest, b);
        
        if(st < a) {
            if(longest < a) break; // st 이전까지 밖에 
            st = longest;
            longest = b;
            if(st >= m) break;
            ans++;
        }
    }
    
    st = longest;
    ans++;
    
    if(st < m) cout << 0;
    else cout << ans;
    
    
    return 0;
}