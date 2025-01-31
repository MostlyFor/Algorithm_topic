#include <iostream>
#include <vector>
using namespace std;


int visit[100001];
vector<int> adj[100001];
int dp[100001][2];
int parents[100001];

// dp[x][0] : 하위 그래프 색칠 x
// dp[x][1] : 하위 그래프 색칠 o

void dfs(int x){
    for(auto nx : adj[x]){
        if(visit[nx]) continue;
        parents[nx] = x;
        visit[nx] = 1;
        dfs(nx);
    }

    dp[x][0] = 0; // 노드 색칠 x
    dp[x][1] = 1; // 노드 색칠 o

    // 해당 배열 채우기
    for(auto nx : adj[x]){
        if(parents[x] == nx) continue;

        dp[x][0] += dp[nx][1]; // 해당 노드 색칠 x 자식 노드 색칠 o
        dp[x][1] += min(dp[nx][0], dp[nx][1]);
    }  
}


int main() {

    int n; cin >> n;

    // 노드 구성
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visit[1] = 1;
    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
    return 0;
}