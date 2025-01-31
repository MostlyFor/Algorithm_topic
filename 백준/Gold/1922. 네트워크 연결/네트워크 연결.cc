#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define P pair<int,int>

bool is_in_set[1001];
vector<P> adj[1001]; // adj[k] k가 출발지이고 {목적지,가중치}
priority_queue<P> q; // 가중치, 목적지


void update(int new_node) {
    for (auto target : adj[new_node]) {
        int target_node = target.first;
        int target_cost = target.second;
        if (is_in_set[target_node]) continue;
        q.push({ -target_cost,target_node });
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int ans = 0;
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    // 0. 1번 노드를 집합 T에 넣기
    is_in_set[1] = true;
    int cnt = 1;
    update(1);

    // 1. 집합 T와 T 외부 노드를 연결하는 최소 간선 (E)
    while (cnt < n) {
        auto next = q.top(); q.pop();
        int target_cost =  - next.first;
        int target_node = next.second;

        if (is_in_set[target_node]) continue;
        // 2. 만약 간선이 새로운 T 외부 노드를 연결한다면 추가 
        is_in_set[target_node] = true; cnt++;
        update(target_node);
        ans += target_cost;
    }

    cout << ans;
    return 0;
}


