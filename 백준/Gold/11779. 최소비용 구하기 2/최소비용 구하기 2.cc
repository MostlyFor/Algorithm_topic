#include <iostream>
#include <queue>
using namespace std;

int n, m;
int st, ed;
vector<pair<int,int>> adj[100000];
int dist[100000];
int parent[100000];

int main(){
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        // adj[b].push_back({a,c});
    }
    
    cin >> st >> ed;
    
    
    for(int i=0; i<=n; i++){
        dist[i] = 1e9;
    }
    
    priority_queue<pair<int,int>> pq;
    pq.push({0, st});
    dist[st] = 0;
    parent[st] = st;
    
    while(pq.size()){
        auto h = pq.top(); pq.pop();
        int here = h.second;
        int cost = -h.first;
        
        if(dist[here] < cost) continue;
        
        
        
        for(auto n : adj[here]){
            int next = n.first;
            int next_cost = n.second;
            
            
            if(dist[next] <= next_cost + cost) continue;
            
            dist[next] = next_cost + cost;
            parent[next] = here;
            pq.push({-dist[next], next});
        }
    }
    
    
    
    vector<int> ans;
    int tmp = ed;
    while(tmp != parent[tmp]){
        ans.push_back(tmp);
        tmp = parent[tmp];
    }
    ans.push_back(tmp);
    cout << dist[ed] << '\n';
    cout << ans.size() << '\n';
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << ' ';
    }
    return 0;
}