#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k;

int candy[30001];
vector<int> adj[30001];
bool visited[30001];
vector<pair<int,int>> arr; // 사람 수, 사탕 수

int ans = 0;

void input(){
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++) cin >> candy[i];
    
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}


void bfs(int x){
    queue<int> q;
    visited[x] = 1;
    q.push(x);
    
    int _people = 1;
    int _candy = candy[x];
    
    while(q.size()){
       int h = q.front(); q.pop();
       
       for(auto n : adj[h]){
           if(visited[n]) continue;
           visited[n] = 1;
           q.push(n);
           
           _people++;
           _candy += candy[n];
       }
    }
    
    arr.push_back({_people, _candy});
}



int f(){
    int num = arr.size(); // 총 친구 수 
    
    
    // dp[i] : 무게 i에서 최대 사탕 수
    vector<int> dp(k, 0);
    
    for(int i=0; i<num; i++){
        int p_cnt = arr[i].first;
        int c_cnt = arr[i].second;
        
        for(int j = k-1; j>=p_cnt; j--){
            dp[j] = max(dp[j], dp[j-p_cnt] + c_cnt);
        }
    }
    
    return dp[k-1];
}

int main(){
    input();
    
    // {사람 수, 사탕 수} 로 바꿈
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        bfs(i);
    }
    
    // test 코드
    // for(auto x : arr){
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    
    // 사람 수를 K 미만으로 하면서 얻을 수 있는 최대 사탕 수
    cout << f();
    
    return 0;
}