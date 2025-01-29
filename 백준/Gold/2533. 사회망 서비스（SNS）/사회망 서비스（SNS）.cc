#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1000001];
bool visit[1000001];
int dp[1000001][2]; // 내 아래 노드 한정 모두 얼리 어답터
int n;

void f(int x){
    visit[x] = 1;
    
    for(auto n : adj[x]){
        if(visit[n]) continue;
        f(n);
        dp[x][0] += dp[n][1];
        dp[x][1] += min(dp[n][1], dp[n][0]);
    }
    
    dp[x][1]++;
}

int main(){
    
    cin >> n;
    
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    f(1);
    
    cout << min(dp[1][0], dp[1][1]);
    
    return 0;
}