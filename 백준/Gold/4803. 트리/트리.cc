#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visit[501]; // 노드 깊이
vector<int> adj[501];
int n_tree;
bool is_cycle;
int t;

void init(){
    n_tree = 0;
    for(int i=0; i<=n; i++){
        visit[i] = 0;
        adj[i].clear();
    }
}

void dfs(int x){
    for(auto n : adj[x]){
        if(visit[n] != 0){
            if(visit[x] - visit[n] > 1) {is_cycle = true;} // 사이클 존재
        }
        else{
            visit[n] = visit[x]+1;
            dfs(n);
        }
    }
}

void solve(){
    
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        if(visit[i]) continue;
        is_cycle = false;
        visit[i] = 1;
        dfs(i);
        if(is_cycle == false) n_tree++;
    }
    
    cout << "Case " << t << ": ";
    if(n_tree == 0) cout << "No trees." << '\n';
    else if(n_tree == 1) cout << "There is one tree." << '\n';
    else cout << "A forest of " << n_tree << " trees." << '\n';
}


int main(){
    while(1){
        t++;
        cin >> n >> m;
        if(n + m == 0) break;
        init();
        solve();
    }
    return 0;
}