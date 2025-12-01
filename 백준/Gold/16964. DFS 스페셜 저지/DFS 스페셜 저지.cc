#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n;
vector<int> adj[100001];
vector<int> seq;
priority_queue <tuple<int,int,int>> pq;
bool visit[100001];
int pro[100001];

void input(){
    cin >> n;
    
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=0; i<n; i++){
        int x; cin >> x;
        pro[x] = i;
        seq.push_back(x);
    }
}

void solve(){
    // 아래 순서가 방문 가능한지만 확인
    // 방문 가능 조건
    // 1. dfs 상 내가 만났던 곳들일 것 
    // 2. 우선순위가 최우선 등급일 것
    // 우선순위의 조건
    // 1. 가장 최근 턴에 추가되었을 것
    
    bool pos = true;
    if(seq[0] != 1){
        cout << 0;
        return;
    }
    
    for(int idx=0; idx<n-1; idx++){
        int x = seq[idx];
        visit[x] = true;
        
        for(auto ne : adj[x]){
            if(visit[ne] == true) continue;
            pq.push(make_tuple(idx, -pro[ne], ne));
        }
        
        // 다음으로 가야하는 곳이 최우선순위인지 체크
        if(get<2>(pq.top()) != seq[idx+1]){
            pos = false;
            break;
        } 
        
        pq.pop();
    }
    
    if(pos) cout << 1;
    else cout << 0;
    
}

int main(){
    input();
    solve();
    return 0;
}