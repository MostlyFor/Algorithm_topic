#include<iostream>

using namespace std;

// 처음에 상근
long long n;

void input() { cin >> n; }

int main() {
	input();

	if (n%2) cout << "SK";
	else cout << "CY";

	return 0;
}