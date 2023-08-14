#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

// 시간복잡도 O(NlogN) : 3 * NlogN + 3Nlog3N + a(N)
// 공간복잡도 O(N + M)

typedef pair<int, int> p;
int parent[100000];
int level[100000];
vector<p> X;
vector<p> Y;
vector<p> Z;
typedef tuple<int, int, int> t;
vector<t> edges;

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
    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        X.push_back({ a,i });
        Y.push_back({ b,i });
        Z.push_back({ c,i });
        parent[i] = i;
        level[i] = 1;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < n-1; i++) {
        edges.push_back(make_tuple(X[i + 1].first - X[i].first, X[i].second, X[i + 1].second));
        edges.push_back(make_tuple(Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second));
        edges.push_back(make_tuple(Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second));
    }
    
    sort(edges.begin(), edges.end());


    for (auto edge : edges) {
        int cost = get<0>(edge);
        int a = get<1>(edge);
        int b = get<2>(edge);
        a = find(a);
        b = find(b);
        if (a == b) continue;
        merge(a, b);
        ans += cost;
    }

    cout << ans;

    return 0;
}