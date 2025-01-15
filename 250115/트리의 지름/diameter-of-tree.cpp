#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> adj[100001];
bool visited[100001];

int longest = 0;
int longest_dist = 0;

// dfs (현재 노드, 현재 노드까지의 길이) -> 최대 간선 번호, 경로의 길이
void dfs(int h, int dist){
    visited[h] = 1;
    if(longest_dist < dist){
        longest_dist = dist;
        longest = h;
    }
    
    for(auto k : adj[h]){
        int n = k.first;
        int cost = k.second;
        if(visited[n]) continue;
        dfs(n, dist+cost);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    // 트리 구성
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    // dfs -> 최대 간선 번호, 경로의 길이
    dfs(1, 0);

    for(int i=0; i<=n; i++) visited[i] = 0;

    dfs(longest, 0);

    cout << longest_dist << '\n';

    return 0;
}