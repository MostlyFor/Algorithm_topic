#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int arr[25000];
int st = 12500; // 다음에 들어갈 원소 자리
int e = 12501; // 다음에 들어갈 원소 자리
// size == e - st;

// st 1 e
// st 1 2 e
// 
// 1 
void push_back(int x) {
	arr[e] = x;
	e++;
}

void push_front(int x) {
	arr[st] = x;
	st--;
}

void front() {
	if (e-st == 1) cout << -1 << '\n';
	else cout << arr[st+1] << '\n';
}

void back() {
	if (e - st == 1) cout << -1 << '\n';
	else cout << arr[e-1] << '\n';
}

void empty() {
	if (e - st == 1) cout << 1 << '\n';
	else cout << 0 << '\n';
}

void size() {
	cout << e - st -1 << '\n';
}

void pop_front() {
	if (e - st == 1) cout << -1 << '\n';
	else {
		cout << arr[st + 1] << '\n';
		st++;
	}
}

void pop_back() {
	if (e - st == 1) cout << -1 << '\n';
	else {
		cout << arr[e - 1] << '\n';
		e--;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		for (auto ch : str) {
			// 만약 추가하는 함수라면
			if (ch == 'h') {
				int num; cin >> num;
				if (str[5] == 'b') {
					push_back(num);
				}
				else push_front(num);
			}
		}

		// 이제 남은건 ppo, size, empty, front ,back
		if (str == "front")
			front();
		else if (str == "back")
			back();

		else if (str == "size")
			size();
		else if (str == "empty")
			empty();
		else if (str == "pop_front")
			pop_front();
		else if (str == "pop_back")
			pop_back();
	}


	return 0;
}