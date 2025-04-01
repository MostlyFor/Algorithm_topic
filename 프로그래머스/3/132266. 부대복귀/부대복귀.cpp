#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dist[100001]; // des에서부터의 거리
vector<int> adj[100001]; // 인접

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {    
    for(auto road : roads){
        int a = road[0];
        int b = road[1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    queue<int> q;
    q.push(destination);
    dist[destination] = 1;
    
    while(q.size()){
        int h = q.front(); q.pop();
        
        for(auto ne : adj[h]){
            if(dist[ne]) continue;
            dist[ne] = dist[h] + 1;
            q.push(ne);
        }
    }
    
    vector<int> answer;

    for(auto s : sources){
        if(dist[s] == 0) answer.push_back(-1);
        else answer.push_back(dist[s]-1);
    }
    
    return answer;
}