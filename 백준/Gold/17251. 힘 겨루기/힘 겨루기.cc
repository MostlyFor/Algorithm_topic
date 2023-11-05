#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n;
int M;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (M < tmp) { // 새로운 최댓값 갱신
			M = tmp;
			arr.clear();
			arr.push_back(i);
			continue;
		}
		else if (M == tmp) { arr.push_back(i); } // 최댓값이랑 값이 같다면
		else continue; // 값 갱신할 필요 없으면 넘어감
	}

	if (arr.front() > n-1 - arr.back()) cout << 'B';
	else if (arr.front() < n-1 - arr.back()) cout << 'R';
	else cout << 'X';
	
	return 0;
}