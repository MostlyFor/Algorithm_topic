#include <string>
#include <vector>
#include <iostream>
using namespace std;
int indegree[1000000];
int outdegree[1000000];
vector<int> adj[1000000];
bool visit[1000000];

int a; // 도넛
int b; // 막대
int c; // 8자

void f(int x){
    visit[x] = 1;
    
    if(indegree[x] >= 2 && outdegree[x] >=2){
        c++;
        return;
    }
    
    if(outdegree[x] == 0) {
        b++;
        return;
    }
    
    for(auto ne : adj[x]){
        if(visit[ne]){
            a++;
            return;
        }
        f(ne);   
    }
    
}



vector<int> solution(vector<vector<int>> edges) {
    // 도넛 - in = 1, out = 1
    // 막대 - in = 0, out = 1 (시작), in =1, out = 1
    // 8자 - in = 2, out = 2(중앙부) or in = 1, out = 1

    
    int gen = -1;
    
    for(auto edge : edges){
        int a = edge[0];
        int b = edge[1];
        adj[a].push_back(b);
        indegree[b]++;
        outdegree[a]++;
        if(indegree[a] == 0 && outdegree[a] > 1) gen = a;
    }
    
    for(auto n : adj[gen]){
        f(n); // f에서 순회
    }
    
    vector<int> answer;
    answer.push_back(gen);
    answer.push_back(a);
    answer.push_back(b);
    answer.push_back(c);
    
    return answer;
}