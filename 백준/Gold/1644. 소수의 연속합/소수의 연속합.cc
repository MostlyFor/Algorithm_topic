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

	while (left <= right) {
		if (sum < n) { //합이 더 작은 경우
			if (right == prime_num.size()) break;
			sum += prime_num[right];
			right++;
			
		}

		else if (sum > n) {
			sum -= prime_num[left];
			left++;
		}
		else {
			ans++;
			if (right == prime_num.size()) break;
			sum += prime_num[right];
			sum -= prime_num[left];
			right++;
			left++;
		}
	}

	cout << ans;

	return 0;
}