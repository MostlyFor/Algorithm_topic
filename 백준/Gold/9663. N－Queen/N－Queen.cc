#include <iostream>
#include <cstdio>
using namespace std;

int n;

int f(int p, int d1, int d2) {
	int v, x, re = 0;
	if (p == n) return 1;
	v = (n & ~(p | d1 | d2));
	while (v) {
		x = v & -v;
		re += f(p | x, (d1 | x) << 1, (d2 | x) >> 1);
		v -= x;
	}
	return re;
}

int main()
{
	cin >> n;
	n = (1 << n) - 1;
    cout << f(0, 0, 0) << endl;
    return 0;
}