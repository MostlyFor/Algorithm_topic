#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
long long treemax[100001 * 4];
long long treemin[100001 * 4];

long long init_max(int node, int s, int e) {
    if (s == e) {
        return treemax[node] = arr[s];
    }

    int mid = (s + e) / 2;
    return treemax[node] = max(init_max(node*2, s, mid), init_max(node*2+1, mid + 1, e));
}

long long init_min(int node, int s, int e) {
    if (s == e) {
        return treemin[node] = arr[s];
    }

    int mid = (s + e) / 2;
    return treemin[node] = min(init_min(node*2, s, mid), init_min(node*2+1, mid + 1, e));
}


long long find_max(int l, int r, int node, int s, int e) {
    // 관여하는 범위가 아니면 생략
    if (e < l || s > r) return -1;

    //관여하는 범위라면 계산
    if (l <= s && e <= r) return treemax[node];

    int mid = (s + e) / 2;

    return max(find_max(l, r, node * 2, s, mid), find_max(l, r, node * 2 + 1, mid + 1, e));
}

long long find_min(int l, int r, int node, int s, int e) {
    // 관여하는 범위가 아니면 생략
    if (e < l || s > r) return 1e10;

    //관여하는 범위라면 계산
    if (l <= s && e <= r) return treemin[node];

    int mid = (s + e) / 2;

    return min(find_min(l, r, node * 2, s, mid), find_min(l, r, node * 2 + 1, mid + 1, e));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    init_max(1, 0, n-1);
    init_min(1, 0, n-1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << find_min(a-1, b-1, 1, 0, n - 1) << ' '<< find_max(a-1, b-1, 1, 0, n - 1) << '\n';
    }
    
    return 0;
}