#include <string>
#include <vector>

using namespace std;

vector<int> adj[101];
int parent[101];
int subtree[101]; // 나를 포함한 서브트리의 개수

// 트리를 구성하고 서브트리를 리턴하는 함수
int f(int x){
    int cnt = 0;
    
    for(int n : adj[x]){
        if(parent[n] != 0) continue;
        cnt++;
        parent[n] = x;
        subtree[x] += f(n);
    }
    
    return ++subtree[x];
}

int solution(int n, vector<vector<int>> wires) {
    
    for(int i=0; i<wires.size(); i++){
        int s = wires[i][0];
        int e = wires[i][1];
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    parent[1] = 1;
    f(1);
    
    int ans = 1e9;
    for(int i=0; i<=n; i++){
        ans = min(ans, abs( n - subtree[i] - subtree[i]));
    }
    
    
    return ans;
}