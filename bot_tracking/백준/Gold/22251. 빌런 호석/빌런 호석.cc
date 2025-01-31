#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;



int n, k, p, x;
vector<int> dict[10];
int ans;

void f(string str, int idx, int res) {
	int tgt = stoi(str);
	if (idx == str.size()) {
		if (tgt == x) return;
		if (tgt <= n && res >= 0 && tgt >= 1) {
			ans++; return;
		}
		return;
	}



	// 해당 자리수 i로 바꿀 예정
	for (int i = 0; i < 10; i++) {
		int h = str[idx] -'0';
		res -= dict[h][i];
		str[idx] = '0' + i;
		f(str, idx + 1, res);
		res += dict[h][i];
		str[idx] = '0' + h;
	}
}


int main() {
	cin >> n >> k >> p >> x;

	// n : 조작 가능한 층 수
	// k : 자릿 수 (6)
	// p : 반전 가능한 수
	// x : 현재 층 수 (7 * 6 최대)

	// 0 : 1,2,3,4,5,6 (0111111)
	// 1 : 23 (0000110)
	// 2 : 12754
	// 3 : 12734
	// 4 : 6723
	// 5 : 16734
	// 6 : 134567
	// 7 : 123
	// 8 : 1234567
	// 9 : 123467

	vector<int> pre_nums = {123456, 23, 12754, 12734, 6723, 16734, 134567, 123, 1234567, 123467};

	vector<int> nums;

	// bit로 변환
	for (int i = 0; i <= 9; i++) {
		int pre = pre_nums[i];
		int num = 0;
		while (pre > 0) {
			int cnt = pre % 10;
			pre /= 10;
			num += 1 << cnt;
		}

		nums.push_back(num);
	}

	// 반전 코드 구현
	// 자릿수마다 반전할 경우 구하고 개수를 빼면서 

	// 서로 몇개를 반전해야 구할 수 있는지 xor 연산을 통해 거리를 알 수 있음
	
	
	// i -> j로 바꾸는데 필요한 반전 수 카운트
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int cnt = 0;
			int bit = nums[i] ^ nums[j];

			while (bit > 0) {
				if (bit % 2) cnt++;
				bit /= 2;
			}
			dict[i].push_back(cnt);
		}
	}

	// K 자릿수로 구현
	string str = to_string(x);
	while(str.size() != k) str = "0" + str;
	
	f(str, 0, p);

	cout << ans;


	return 0;
}