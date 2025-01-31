#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, e;
int a, b;

// 다익스트라 1에서 시작
// 다익스트라 2에서 N에서 시작




vector<pair<int,int>> adj[801];
int dist1[801];
int distn[801];
int dista[801];

void f(){
    priority_queue <pair<int,int>> pq;
    pq.push(make_pair(0, 1));
    dist1[1] = 0;
    
    while(pq.size()){
        auto h = pq.top(); pq.pop();
        int cost = - h.first;
        int here = h.second;

        
        if (dist1[here] < cost) continue;
        
        for(auto n : adj[here]){
            int next_cost = cost + n.second;
            int next = n.first;
            
            // 다익스트라 갱신
            if(dist1[next] > next_cost){
                dist1[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}


void g(){
    priority_queue <pair<int,int>> pq;
    pq.push(make_pair(0, n));
    distn[n] = 0;
    
    while(pq.size()){
        auto h = pq.top(); pq.pop();
        int cost = - h.first;
        int here = h.second;
        
        if (distn[here] < cost) continue;
        
        for(auto n : adj[here]){
            int next_cost = cost + n.second;
            int next = n.first;
            
            // 다익스트라 갱신
            if(distn[next] > next_cost){
                distn[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}

void h(){
    priority_queue <pair<int,int>> pq;
    pq.push(make_pair(0, a));
    dista[a] = 0;
    
    while(pq.size()){
        auto h = pq.top(); pq.pop();
        int cost = - h.first;
        int here = h.second;
        
        if (dista[here] < cost) continue;
        
        for(auto n : adj[here]){
            int next_cost = cost + n.second;
            int next = n.first;
            
            // 다익스트라 갱신
            if(dista[next] > next_cost){
                dista[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}


int main(){
    cin >> n >> e;

    for (int i = 1; i <= n; i++) {
        dist1[i] = 1e9;
        distn[i] = 1e9;
        dista[i] = 1e9;
    }

    for (int i = 0; i < e; i++) {
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        adj[a1].push_back({b1, c1});
        adj[b1].push_back({a1, c1});
    }

    cin >> a >> b;
    
    
    f();
    g();
    h();
    // 1 -> a , a -> b, b -> N
    // 1 -> b, b -> a, a -> N 까지 중 최선
    int ans = 0;
    ans = min(dist1[a] + dista[b] + distn[b], dist1[b] + dista[b] + distn[a]);
    
    if(ans >= 1e9 || ans < 0) cout << -1;
    else cout << ans;
    
    
    return 0;
}