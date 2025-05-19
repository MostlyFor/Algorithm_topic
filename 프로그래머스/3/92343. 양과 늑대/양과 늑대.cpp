#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> adj[18]; 
int pos_node[18];
int visit[18];
int answer = 0;
int n;

void dfs(vector<int>& info, int h, int s, int w){
    if(s <= w) return; // 전부 다 돌았거나, 늑대가 더 많으면 종료
    answer = max(answer, s); // 값 초기화
    
    // 방문 가능한 edge들을 모두 방문하기
    for(int i=0; i<n; i++){
        // 만약 방문 가능하면 방문
        if(visit[i] == 0 && pos_node[i]) {
            visit[i] = 1;
            vector<int> new_pos;
            
            // 경로 체크용 
            for(auto k : adj[i]) {
                if(pos_node[k] == 0) new_pos.push_back(k);
                pos_node[k] = 1;
            }
            dfs(info, i, s+(info[i] == 0), w + (info[i] == 1));
            visit[i] = 0;
            for(auto k : new_pos) pos_node[k] = 0;
            
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    // 양이 늑대에게 잡아먹히지 않도록 하면서 최대한 많은 수의 양 모으기
    
    for(int i=0; i<edges.size(); i++){
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    visit[0] = 1;
    for(auto n : adj[0]) pos_node[n] = 1;
    dfs(info, 0, 1, 0);
    
    return answer;
}