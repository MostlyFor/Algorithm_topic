#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[50001];
int parents[50001][21];
int depth[50001];

int n;
int max_depth = 0;
int ans = 1;


void dfs(int x){
    for(auto nx : adj[x]){
        if(depth[nx]) continue;
        parents[nx][0] = x;
        depth[nx] = depth[x]+1;
        max_depth = max(max_depth, depth[nx]);
        dfs(nx);
    }
}


int lca(int a, int b){
    // 높이 맞추기
    if(depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }

    // a 높이 올려주기
    for(int i=20; i>=0; i--){
        if(depth[a] - (1 << i) >= depth[b]){
            a = parents[a][i];
        }
    }

    // cout << a << ' ' << b << '\n';
    // cout << parents[a][0] << ' ' << parents[b][0] << '\n';

    if(a == b) return a; // 애초에 같음

    // 공통 조상 -1 찾기
    for(int i=20; i>=0; i--){
        if(parents[a][i] == 0) continue;
        if(parents[a][i] != parents[b][i]){
            a = parents[a][i];
            b = parents[b][i];
        }
    }

    return parents[a][0];
}



int main(){
    cin >> n;
    
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[1] = 1;
    dfs(1); // 부모, 깊이 배열 초기화

    
    // 2차원 부모 배열 초기화
    for(int i=1; i<n; i++){
        // step = 1 << i;
        if(max_depth - 1 < (1 << i)) break; // step이 깊이보다 크면 어차피 0임

        for(int j=1; j<=n; j++){
            parents[j][i] = parents[parents[j][i-1]][i-1];
        }
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        ans = 1;

        cout << lca(a,b) << '\n';
    }

    return 0;
}