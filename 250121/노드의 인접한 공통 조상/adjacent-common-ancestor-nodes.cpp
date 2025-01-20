#include <iostream>
#include <vector>
using namespace std;

int parents[10001];
int depth[10001];
vector<int> adj[10001];
int root = 0;
int ans = 0;


void dfs(int x){
    for(auto nx : adj[x]){
        if(nx == parents[x]) continue;
        depth[nx] = depth[x]+1;
        dfs(nx);
    }
}

void lca(int a, int b){
    if(a == b) {
        ans = a;
        return;
    }

    int da = depth[a];
    int db = depth[b];

    if(da < db) lca(a, parents[b]);
    else if (da > db) lca(parents[a], b);
    else lca(parents[a], parents[b]);

}


int main() {
    int n; cin >> n;
    
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        parents[b] = a;
    }

    for(int i=0; i<n; i++) if(parents[i] == 0) root = i;

    int a, b; cin >> a >> b; // a와 b의 공통 조상 찾기

    dfs(root); // 레벨 초기화 함수

    lca(a, b);

    cout << ans;
    return 0;
}