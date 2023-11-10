#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> arr(10,0); // 누를 수  없는
int h = 100; //현재 채널
int n; // 목표
int ans = 1e9;

void check_up(int dist) { // 해당 지점이 확인 가능한지
	// 위로 큰 경우
	int up = n + dist;
	string st = to_string(up);
	for (auto ch : st) {
		if (arr[ch - '0'] == 1) return;
	}
	int k = dist + st.size();
	ans = min(ans, k);
	return;
}

void check_down(int dist) {

	int down = n - dist;
	if (down < 0) return; 
		string st = to_string(down);
		for (auto ch : st) {
			if (arr[ch - '0'] == 1) return;
		}
	int k = dist + st.size();
	ans = min(ans, k);
	return;
}



int main() {
	cin >> n;
	if (h == n) { cout << 0; return 0; } 

	int cnt; cin >> cnt; // 고장난 버튼
	
	for (int i = 0; i < cnt; i++) {
		int tmp; cin >> tmp;
		arr[tmp] = 1;
	}

	// 풀이 시작

	// 어떠한 조합을 눌렀을 때 목표를 맞출 수 있는지

	// 1. 목표지점부터 시작해서 나와 가장 거리가 가까운 지점을 방문하고 거기를 올 수 있는지 확인
	for (int dist = 0; dist < 499900; dist++) {
		check_up(dist);  // 목표 지점
		check_down(dist);
	}
	

	if (ans < abs(n - h)) cout << ans;
	else cout << abs(n - h);

	return 0;
}