#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, m;
int visit[1000001];
int answer = 0;

bool in_range(int x){
    return 0<= x && x <=n;
}

int main(){
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int tmp; cin >> tmp;
        q.push(tmp);
        visit[tmp] = 1;
    }
    
    while(q.size()){
        int h = q.front(); q.pop();
        
        for(int i=0; i<=20; i++){
            int n = h ^ (1 << i);
            if(!in_range(n)) continue;
            if(visit[n]) continue;
            visit[n] = visit[h]+1;
            answer = max(answer,visit[n]);
            q.push(n);
        }
    }
    
    cout << answer-1 << '\n';
    
    
    return 0;
}