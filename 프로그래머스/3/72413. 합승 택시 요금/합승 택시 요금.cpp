#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int,int>> adj[201]; // [a] = {b, cost}
int dist[201][201];


// 다익스트라
void f(int st, int n){
    for(int i=1; i<=n; i++){
        dist[st][i] = 1e9;
    }
    dist[st][st] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, st});
    
    while(pq.size()){
        int cost = -pq.top().first;
        int he = pq.top().second;
        pq.pop();
        
        // if(dist[st][he] <= cost) continue;
        
        for(auto tmp : adj[he]){
            int ne = tmp.first;
            int pay = tmp.second;
            
            int new_cost = cost + pay;
            
            if(dist[st][ne] <= new_cost) continue;
            dist[st][ne] = new_cost;
            pq.push({-new_cost, ne});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    // s : 출발 지점, a 도착지점, b 도착지점, n 개수
    
    for(int i=0; i<fares.size(); i++){
        int x1 = fares[i][0];
        int x2 = fares[i][1];
        int cost = fares[i][2];
        
        adj[x1].push_back({x2, cost});
        adj[x2].push_back({x1, cost});
    }
    
    for(int i=1; i<=n; i++){
        f(i, n);
    }
    
    
    long long ans = 1e9;
    
    for(int i=1; i<=n; i++){
        // n 번째를 경유지로 할 경우
        long long total = dist[s][i] + dist[i][a] + dist[i][b];
        ans = min(total, ans);
    }
    return ans;
    
    // test용도
    // for(int i=1; i<=n; i++){
    //     cout << dist[1][i] << ' ';
    // }
    // cout << '\n';
}