#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int req[32001]; // 해당 문제를 풀기 위해 풀려야 하는 번호 수
vector<int> go[32001]; // 해당 번호를 필요로 하는 문제들
int n, m;
priority_queue <int> pq;


int main(){
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        go[a].push_back(b);
        req[b]++;
    }
    
    for(int i=1; i<=n; i++) if(req[i] == 0) pq.push(-i);
    
    while(pq.size()){
        int h = -pq.top(); pq.pop();
        cout << h << ' ';
        
        
        for(int ne : go[h]){
            req[ne]--;
            if(req[ne] == 0) pq.push(-ne);
        }
    }
    
    return 0;
}