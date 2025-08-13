#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int pointer[100001]; 
int indegree[100001];


void solve(){
    queue<int> q; // 차수만큼
    cin >> n;
    for(int i=1; i<=n; i++) indegree[i] = 0;
    for(int i=1; i<=n; i++) {
        cin >> pointer[i];
        indegree[pointer[i]]++;
    }
    for(int i=1; i<=n; i++) if(indegree[i] == 0) q.push(i);
    
    int not_in_cycle = 0;
    
    while(q.size()){
        int h = q.front(); q.pop();
        not_in_cycle++;
        if(--indegree[pointer[h]] == 0) q.push(pointer[h]);
    }

    cout << not_in_cycle << '\n';

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}