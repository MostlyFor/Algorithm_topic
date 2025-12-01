#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> adj[300001];
int visit[300001];

void input(){
    cin >> n;
    for(int i=0; i<n-2; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void bfs(int st, int color){
    queue<int> q;
    q.push(st);
    visit[st] = color;
    
    while(q.size()){
        int he = q.front(); q.pop();
        
        for(auto ne : adj[he]){
            if(visit[ne]) continue;
            visit[ne] = color;
            q.push(ne);
        }
    }
}

void solve(){
    bfs(1, 1);
    
    for(int i=1; i<=n; i++){
        if(visit[i]) continue;
        cout << 1 << ' ' << i << '\n';
        return;
    }
    
    
}


int main(){
    input();
    solve();
    return 0;
}