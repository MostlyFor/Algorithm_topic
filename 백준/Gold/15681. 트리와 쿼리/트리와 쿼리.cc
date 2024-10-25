#include <iostream>
#include <vector>
using namespace std;

int n, r, q; // r: 루트의 번호

vector<int> adj[100001];
int par[100001];
int answer[100001];
// 부모 갱신
void f(int cur, int parent){
    
    par[cur] = parent;
    
    for(auto next : adj[cur]){

        if(par[next] != 0) continue;;
        
        f(next, cur);
    }
}

int cnt;
// 서브트리 개수 리턴
int g(int x){
    cnt+=1;
    answer[x] = 1;
    
    for(auto next : adj[x]){
        if(next == par[x]) continue;
        answer[x] += g(next);
    }
    
    return answer[x];
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> r >> q;
    
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    f(r, -1); // 트리 부모 자식 관계 갱신해주기
    
    g(r); // 돌면서 자신 포함 자신의 하위 트리 개수 갱신
    
    
    for(int i=0; i<q; i++){
        int tmp; cin >> tmp;
        cout << answer[tmp] << '\n';
    }
    return 0;
}