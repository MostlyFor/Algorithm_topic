#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;



int board[201][201];
int parent[201];
int level[201];

// 부모 노드 찾기
int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}


void merge(int a, int b) {

    b = find(b);
    a = find(a);

    // a를 항상 깊게
    if (level[a] < level[b]) swap(a, b);

    parent[b] = a;

    if (level[a] == level[b]) level[a]++;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // init
    for (int i = 1; i <= n; i++) {
        level[i] = 1;
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            if (tmp == 1) {
                merge(i+1, j+1);
            }
        }
    }


    int root;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            cin >> root; continue;
        }
        int plan; cin >> plan;
        if (find(root) != find(plan)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}