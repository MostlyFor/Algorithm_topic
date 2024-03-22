#include <iostream>
#include <vector>
using namespace std;


int n, m;

int parent[1000001];
int  level[1000001];
// x 의 조상을 리턴
int find(int x) {
	if (x == parent[x]) return x;
	return find(parent[x]);
}


void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return;

	// level 개념 도입 - 트리를 얕게 만들기
	if (level[pa] < level[pb]) {
		parent[pa] = pb;
	}
	else if(level[pa] > level[pb]){
		parent[pb] = pa;
	}
	else {
		parent[pb] = pa;
		level[pa]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	// 초기 세팅
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		level[i] = 1;
	}


	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		// 명령 0 -> find
		if (a == 1) {
			if (find(b) == find(c)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else merge(b, c);
	}

	return 0;
}