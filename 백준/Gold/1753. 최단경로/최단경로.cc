#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v, e;
int st;

priority_queue <pair<int,int>> pq; // 여기까지의 거리, 현재 노드
int dist[20001];
vector<pair<int,int>> adj[20001]; // adj[a] = {b,c} a 출발 b 까지 거리 c

int main(){
    cin >> v >> e;
    cin >> st;
    
    for(int i=0; i<=v; i++){
        dist[i]= 1e9;
    }
    
    for(int i=0; i<e; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    
    
    dist[st] = 0;
    pq.push({0, st});
    
    
    while(pq.size()){
        int cost = -pq.top().first;
        int he = pq.top().second;
        pq.pop();
        
        if(dist[he] < cost) continue;
        
        for(auto tmp: adj[he]){
            int ne = tmp.first;
            int ne_cost = tmp.second;
            
            if(dist[he] + ne_cost >= dist[ne]) continue;
            dist[ne] = dist[he] +ne_cost;
            pq.push({-dist[ne], ne});
        }
    }
    
    for(int i=1; i<=v; i++){
        if(dist[i] == 1e9) cout << "INF"<< '\n';
        else cout << dist[i] << '\n';
    }
    
    return 0;
}