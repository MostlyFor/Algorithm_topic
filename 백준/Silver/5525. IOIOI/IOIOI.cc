#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
string str;


int main() {
	cin >> n; // n개의 O와 n+1개의 I -> 반전은 2n번
	cin >> m >> str;

	// I로 시작해서 반전이 몇개인지만 세면 될 듯
	vector<int> dp(m, 0); // 내 앞에 반전이 연속 몇번 되는지
	int ans = 0;
	for (int i = m-2; i >= 0; --i) {
		if (str[i] != str[i + 1]) dp[i] = dp[i + 1] + 1;
		if (str[i] == 'I' && dp[i] >= 2 * n)ans++;
	}

	cout << ans;
	
	return 0;
}