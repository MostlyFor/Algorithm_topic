#include <string>
#include <vector>

using namespace std;

vector<int> adj[101];
int subtree[101]; // 나를 포함한 서브트리의 개수
int ans = 1e9;
int N;

// 트리를 구성하고 서브트리를 리턴하는 함수
int f(int x, int p){
    
    for(int n : adj[x]){
        if(n == p) continue;
        subtree[x] += f(n, x);
    }
    
    ++subtree[x];
    ans = min(ans, abs(N - subtree[x] - subtree[x]));
    return subtree[x];
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    for(int i=0; i<wires.size(); i++){
        int s = wires[i][0];
        int e = wires[i][1];
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    f(1, 1);

    for(int i=0; i<=n; i++){
        ans = min(ans, abs( n - subtree[i] - subtree[i]));
    }
    
    
    return ans;
}