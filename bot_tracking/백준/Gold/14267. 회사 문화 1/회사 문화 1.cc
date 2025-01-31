#include <iostream>
#include <vector>
using namespace std;

int nodes[100001];
vector<int> adj[100001]; // 자식 노드
int n, m;

void f(int x){
    for(auto nx : adj[x]){
        nodes[nx] += nodes[x];
        f(nx);
    }
}


int main(){
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        int a = 0; cin >> a;
        if(a==-1) continue;
        adj[a].push_back(i);
    }
    
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        if(a == 1) continue;
        nodes[a] += b;
    }
    
    
    f(1);
    
    
    
    for(int i=1; i<=n; i++) cout << nodes[i] << ' ';
    return 0;
}