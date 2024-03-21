#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> adj[1001]; // adj[x][y] x -> y 가능한지
int visit[1001];
int cnt = 0;
void dfs(int h){

    for(auto n : adj[h]){
        if(visit[n]) continue;
        visit[n] = 1;
        dfs(n);
        cnt++;
    }
}

int main(){
    cin >> n >> m; 
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visit[1] = 1;
    dfs(1);

    cout << cnt;

    return 0;
}