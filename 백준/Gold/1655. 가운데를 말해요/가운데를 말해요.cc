#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n; // 백준이가 외치는 정수의 개수 N
	priority_queue<int> incq, decq;
	
	int tmp2; cin >> tmp2; incq.push(tmp2); cout << tmp2 << '\n';
	for (int i = 1; i < n; i++) {
		int tmp; cin >> tmp;

		// 개수가 왼쪽이 하나 높은 경우
		if (incq.size() == decq.size() + 1) {
			incq.push(tmp);
			decq.push(-incq.top()); incq.pop();
		}

		// 개수가 같은 경우 
		else  if (incq.size() == decq.size()) {
			decq.push(-tmp);
			incq.push(-decq.top()); decq.pop();
		}
		cout << incq.top() << '\n';
	}
	return 0;
}