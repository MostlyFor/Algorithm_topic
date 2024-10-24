#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> adj[100001];
int dist[100001];

void dfs(int here){
    
    for(auto tmp : adj[here]){
        int next = tmp.first;
        int cost = tmp.second;
        
        if(dist[next]!=0) continue;
        dist[next] = dist[here] + cost;
        dfs(next);
    }
}

int main(){
    int n; cin >> n;
    
    
    // 트리 구성
    for(int i=0; i<n; i++){
        int idx; cin >> idx;
        
        while(1){
            int a; cin >> a;
            if(a==-1) break;
            int b; cin >> b;
            
            
            adj[idx].push_back({a,b});
        }
    }
    
    dist[1] = 1;
    dfs(1);

    int idx = 0;
    int max_dist = 0;
    for(int i=0; i<=n; i++) {
        if(dist[i] > max_dist) {
            idx = i;
            max_dist = dist[i];
        }
        dist[i] = 0;
    }
    
    dist[idx] = 1;
    dfs(idx);
    
    for(int i=0; i<=n; i++) {
        if(dist[i] > max_dist)
            max_dist = dist[i];
    }
    
    
    cout << max_dist-1;
    
    return 0;
}