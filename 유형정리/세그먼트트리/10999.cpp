#include <iostream>
#include <vector>
using namespace std;

long long arr[1000000];
long long tree[1000000 * 4];
long long lazy[1000000 * 4];

long long init(int node, int s, int e){
	if (s == e) return tree[node] = arr[e];
	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

void update_lazy(int node, int s, int e) {
	// 업데이트 할 게 없다면 pass
	if (lazy[node] == 0) return;
	tree[node] += (e - s + 1) * lazy[node];
	// 자식한테 lazy 물려주기
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}


long long find(int l, int r, int node, int s, int e) {
	update_lazy(node, s, e);
	if (e < l || r < s) return 0;

	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return find(l, r, node * 2, s, mid) + find(l, r, node * 2 + 1, mid + 1, e);
}


void update(int node, int s, int e, int l, int r, long long diff) {
	update_lazy(node, s, e);
	// 만약 상관없는 부분이라면 넘어감
	if (r < s || e < l) return;

	// 자식 노드들을 모두 업데이트 해야 하는 상황이라면 lazy 물려주기
	if (l <= s && e <= r) {
		tree[node] += (e - s + 1)*diff;
		if (s == e) return;
		lazy[node * 2] += diff;
		lazy[node * 2 + 1] += diff;
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, l,r, diff);
	update(node * 2 + 1, mid + 1,e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m, k; cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(1, 0, n - 1);

	for (int i = 0; i < m+k; i++) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			long long a, b, c;
			cin >> a >> b >> c;
			update(1, 0, n - 1, a-1, b-1, c);
		}

		else if (cmd == 2) {
			long long a, b;
			cin >> a >> b;
			cout << find(a-1, b-1, 1, 0, n - 1) << '\n';
		}
	}

	return 0;
}