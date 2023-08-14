#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

// 시간복잡도 O(MlogM + M a(N))
// 공간복잡도 O(N + M)

// 크루스칼 알고리즘 풀이
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

