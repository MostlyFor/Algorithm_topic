#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

vector<long long> arr;
long long tree[1000000 * 4 + 1];


long long init(int node, int s, int e) {
    if (s == e) {
        return tree[node] = arr[s];
    }

    int mid = (s + e) / 2;

    tree[node * 2] = init(node*2,s, mid);
    tree[node * 2 + 1] = init(node * 2 + 1, mid+1, e);
    return tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int x, long long v, int node, int s, int e) {
    if (x < s || x > e) return;
    tree[node] += v - arr[x];
    if (s == e) return;
    int mid = (s + e) / 2;
    update(x, v, node*2, s, mid);
    update(x, v, node*2 +1, mid + 1, e);
}

// l 부터 r까지의 부분 합
// node는 s부터 e까지의 부분합임
long long sum(int l, int r, int node, int s, int e) {
    // 만약 현재 노드가 l부터 r이랑 관계 없을 경우
    if (s > r || e < l) return 0;

    // 관계 있는 경우
    if(l<=s && r>=e) {
        return tree[node];
    }

    // 만약 현재 노드가 관계 있을 경우
    int mid = (s + e) / 2;

    return sum(l, r, node * 2, s, mid) + sum(l, r, node * 2+1, mid + 1, e);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    arr.push_back(0);

    for (int i = 0; i < n; i++) {
        long long tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    init(1, 1, n);
    int cnt = m + k;
    while (cnt--) {
        long long cmd, l, r;
        cin >> cmd >> l >> r;

        if (cmd == 2) cout << sum(l, r, 1, 1, n) << '\n';
        else {
            update(l, r, 1, 1, n);
            arr[l] = r;
        }
        
    }

    return 0;
}