#include <string>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

priority_queue<tuple<int,int,int>> pq; // 건설 비용, a, b

int parent[101]; // 해당 트리의 루트 노드
int level[101]; 

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){    
    // if(level[a] == level[b]){
    //     level[a]++;
    //     parent[b] = a;
    // }
    // if(level[a] < level[b]){
    //     int tmp = a;
    //     a = b;
    //     b = tmp;
    // }
    // a 가 항상 더 깊게 초기화
    parent[b] = a;
    
}

int solution(int n, vector<vector<int>> costs) {
    
    int answer = 0; // 총 건설 비용
    
    for(int i=0; i<n ;i++){
        parent[i] = i;
        level[i] = 1;
    }
    
    // 간선 적은 것부터 꺼낼 수 있게 
    for(auto c : costs){
        pq.push(make_tuple(-c[2],c[0],c[1]));
    }
    
    while(pq.size()){
        auto tmp = pq.top(); pq.pop();
        int cost = -get<0>(tmp);
        int a = get<1>(tmp);
        int b = get<2>(tmp);
        
        a = find(a);
        b = find(b);
        
        if(a == b) continue;
        
        merge(a, b);
        answer += cost;
    }
    
    return answer;
}