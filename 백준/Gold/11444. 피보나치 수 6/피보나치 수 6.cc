#include <iostream>
#include <unordered_map>
using namespace std;

#define mod 1000000007
long long ans, n;

unordered_map <long long, unsigned long long> hmap;

unsigned long long f(long long k) {

	if (hmap.find(k) != hmap.end()) return hmap[k];

	// 만약 k가 홀수이면
	if (k % 2) hmap[k] = (f(k / 2 + 1) * f(k / 2 + 1)) % mod + (2 * f(k / 2 + 1) * f(k / 2)) % mod;

	// k가 짝수이면
	else  hmap[k] = (f(k / 2 + 1) * f(k / 2 + 1)) % mod + (f(k / 2) * f(k / 2)) % mod;

	hmap[k] %= mod;

	return hmap[k];
}



int main() {
	cin >> n;

	// f(k+2) = f(k+1) + f(k)
	// f(k+3) = 2f(k+1) + f(k)
	// f(k+4) = 3f(k+1) + 2f(k)
	// f(k+5) = 5f(k+1) + 3f(k)

	// 일반화된 점화식 (해당 문제에서 f(0) = 0 f(1) = 1) 
	// f(k+a) = f(a+1)f(k+1) + f(a)f(k)  (a >=2)

	// if a =k 
	// f(2k) = f(k+1)^2 + f(k)^2

	// if a = k+1
	// f(2k+1) = f(k+2)f(k+1) + f(k+1)f(k) = f(k+1)^2 + 2f(k+1)f(k)
	// ex) f(9) = f(6)f(5) + f(5)f(4)
	// 5 * 3 + 3 * 2

	hmap[1] = 0;
	hmap[2] = 1;
	hmap[3] = 1;
	hmap[4] = 2;
	hmap[5] = 3;
	hmap[6] = 5;
	cout << f(n+1);



	return 0;
}