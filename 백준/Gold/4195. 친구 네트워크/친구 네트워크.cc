#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int n, m;
int T;
int  parent[200001];
int   level[200001];
int network[200001];


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
		network[pb] += network[pa];
	}
	else if(level[pa] > level[pb]){
		parent[pb] = pa;
		network[pa] += network[pb];
	}
	else {
		parent[pb] = pa;
		network[pa] += network[pb];
		level[pa]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<string, int> hmap; // 사람 이름 : 번호 매칭
	int cnt = 1;

	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 1; i <= 200000; i++) {
			parent[i] = i;
			level[i] = 1;
			network[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;

			if (hmap[str1] == 0) hmap[str1] = cnt++;
			
			if (hmap[str2] == 0) hmap[str2] = cnt++;
			
			int a = hmap[str1];
			int b = hmap[str2];

			merge(a, b);
			a = find(a);
			
			cout << network[a] << '\n';

		}
	}
	
	return 0;
}