#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

// 시간복잡도 O(MlogM + M a(N))
// 공간복잡도 O(N + M)


// 크루스칼 알고리즘 풀이
/*
int parent[1001];
int level[1001];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    if (level[a] < level[b])
        swap(a, b);
    if (level[a] == level[b]) level[a]++;
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int m; cin >> m;
    vector<pair<int,int>> edges;
    int ans = 0;
    
    // 0. 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i; level[i] = 1;
    }
    
    // 1. 간선들을 모두 받아서 정렬 (MlogM)
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({ c,{a * 10000 + b} });
    }
    sort(edges.begin(), edges.end());
    // 2. 가장 짧은 간선을 가져오고 간선의 노드가 같은 집합이면 추가, 그렇지 않으면 추가 안함 (M a(N))
    for (auto edge : edges) {
        int w = edge.first;
        int a = edge.second / 10000;
        int b = edge.second % 10000;
        a = find(a);
        b = find(b);
        if (a == b) continue;
        merge(a, b);
        ans += w;
    }

    cout << ans;

    return 0;
}

*/

// 프림 알고리즘 풀이

// 시간복잡도 O(ElogV) : 
// 공간복잡도 O(N + M)

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


