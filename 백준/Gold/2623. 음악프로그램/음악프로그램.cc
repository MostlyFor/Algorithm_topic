#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> pointer[1001]; // 내가 누구를 가리키고 있는지
int indegree[1001];
vector<int> answer;


int main(){
    int n, m; cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int cnt; cin >> cnt;
        int bef; cin >> bef;
        for(int j=0; j<cnt-1; j++){
            int aft; cin >> aft;
            pointer[bef].push_back(aft);
            bef = aft;
            indegree[aft]++;
        }
    }
    
    for(int i=1; i<=n; i++){
        if(indegree[i] != 0) continue;
        
        int st = i;
        queue<int> q; // 앞으로 출력할 후보들
        q.push(st);
        
        while(q.size()){
            st = q.front(); q.pop();
            answer.push_back(st);
            indegree[st] = -1;
            
            for(auto ne : pointer[st]){
                indegree[ne]--;
                if(indegree[ne] == 0) q.push(ne);
            }
        }
    }
    
    if(answer.size() != n) cout << '0';
    else{
        for(auto k : answer) cout << k << '\n';
    }
    
    return 0;
}