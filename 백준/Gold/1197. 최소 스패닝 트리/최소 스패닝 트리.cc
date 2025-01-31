#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


// 시간복잡도 O(ElogE + E * a(V)) : a 애커만 함수
// 공간복잡도 O(E+V)

vector<int> per;
vector<int> level;
vector<pair<int,int>> edges; // (가중치, 원래 인덱스)
vector<pair<int, int>> edges_sum; // (노드 1, 노드 2)

int find(int x) {
    if (per[x] == x) return x;
    return per[x] = find(per[x]);
}

void merge(int a, int b) {
    if (level[a] < level[b])
        swap(a, b);
    per[b] = a;
    if (level[a] == level[b])
        level[a] ++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E; cin >> V >> E;
    
    for (int i = 0; i <= V; i++) {
        per.push_back(i);
        level.push_back(1);
    }

    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges_sum.push_back({ a,b });
        edges.push_back({ c,i });
    }

    // 최소 간선 정렬 (ElogE)
    sort(edges.begin(), edges.end());
   
    int ans = 0;
    // 최소 간선이 새로운 두 노드를 연결하는지 확인
    for (auto edge : edges) {
        int f = edges_sum[edge.second].first;
        int s = edges_sum[edge.second].second;
        f = find(f);
        s = find(s);
        if (f == s) continue;

        merge(f, s);
        ans += edge.first;
    }

    cout << ans;

    return 0;
}

