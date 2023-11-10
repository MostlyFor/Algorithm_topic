#include <iostream>
#include <vector>
using namespace std;

vector<int> prime_num;
bool is_not_prime[4000001] = {0,};
int ans = 0;


int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	// 소수 구하기
	for (int i = 2; i <= n; i++) {
		if (is_not_prime[i]) continue;
		else if (is_not_prime[i] == 0) prime_num.push_back(i);
		for (long long j = i; j * i <= n; j++) {
			is_not_prime[i * j] = 1;
		}
	}

	int left = 0;
	int right = 1;
	long long sum = prime_num[left];
	prime_num.push_back(1e9);
	while (left < right) {
		if (sum > n) sum -= prime_num[left++];
		else if (sum < n) sum += prime_num[right++];
		else {
			ans++;
			sum += prime_num[right++];
			sum -= prime_num[left++];
		}
	}

	cout << ans;

	return 0;
}