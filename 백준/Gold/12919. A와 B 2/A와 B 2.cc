#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;

int n;
int ans = 0;
string tgt;
void dfs(vector<int>& arr, string str) {
	string tmp = str;
	reverse(str.begin(), str.end());
	if (!(tgt.find(tmp)!=string::npos || tgt.find(str)!= string::npos)) return;

	str = tmp;

	// 만약 같다면
	if (arr[0] == arr[2] && arr[1] == arr[3]) {
		if (str == tgt) {
			ans = 1; return;
		}
	}

	// A의 개수가 부족하면
	if (arr[0] < arr[2]) {
		arr[0]++;
		dfs(arr, str + "A");
		arr[0]--;
	}

	// B의 개수가 부족하면
	if (arr[1] < arr[3]) {
		arr[1]++;
		reverse(str.begin(), str.end());
		dfs(arr, "B" + str);
		reverse(str.begin(), str.end());
		arr[1]--;
	}

}


int main() {
	string str;
	cin >> str >> tgt;

	// 모든 조합 할 필요 없이 생각해보면 꼭 안해도 되는 조합이 있긴 함

	vector<int> arr(4, 0);
	for (auto ch : str) {
		if (ch == 'A') arr[0]++;
		else arr[1]++;
	}

	for (auto ch : tgt) {
		if (ch == 'A') arr[2] ++;
		else arr[3]++;
	}


	dfs(arr, str);

	cout << ans;
	return 0;

}