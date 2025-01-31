#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;



int ans = 0;
int n;

void f(int dir, int cnt, int maximum, vector<vector<int>> board) {
	if (cnt == 5) {
		ans = max(maximum, ans);
		// 끝내기
		return;
	}

	//블록 옮기기
		// 오른쪽으로 옮기기
	if (dir == 0) {
		// 각 행마다
		for (int i = 0; i < n; i++) {
			stack<pair<int, bool>> st; // 들어간 숫자, 이미 통합 되었는지
			for (int k = n - 1; k >= 0; k--) {
				if (board[i][k] == 0) continue;
				if (st.size() == 0) st.push({ board[i][k], 0 });
				// 만약 숫자가 같고, 통합이 안되었다면 통합
				else if (st.top().first == board[i][k] && st.top().second == 0) {
					st.pop(); st.push({ board[i][k] * 2,1 });
				}
				// 통합이 안된다면 그냥 넣기
				else{
					st.push({ board[i][k],0 });
				}
			}

			while (st.size() != n) st.push({ 0,0 });

			for (int k = 0; k <= n - 1; k++) {
				if (st.size()) {
					board[i][k] = st.top().first; st.pop();
				}
				else
					board[i][k] = 0;


				maximum = max(maximum, board[i][k]);
			}
		}
	}
	 // 왼쪽으로 옮기기
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			stack<pair<int, bool>> st; // 들어간 숫자, 이미 통합 되었는지
			for (int k = 0; k <= n-1; k++) {
				if (board[i][k] == 0) continue;
				if (st.size() == 0) st.push({ board[i][k], 0 });
				// 만약 숫자가 같고, 통합이 안되었다면 통합
				else if (st.top().first == board[i][k] && st.top().second == 0) {
					st.pop(); st.push({ board[i][k] * 2,1 });
				}
				// 통합이 안된다면 그냥 넣기
				else {
					st.push({ board[i][k],0 });
				}
			}

			while (st.size() != n) st.push({ 0,0 });

			// 다시 채워넣기
			for (int k = n - 1; k >= 0; k--) {
				if (st.size()) {
					board[i][k] = st.top().first; st.pop();
				}
				else
					board[i][k] = 0;

				maximum = max(maximum, board[i][k]);
			}
		}
	}
	// 위쪽으로 옮기기
	else if (dir == 2) {
		for (int k = 0; k < n; k++) {
			stack<pair<int, bool>> st; // 들어간 숫자, 이미 통합 되었는지
			for (int i = 0; i <= n - 1; i++) {
				if (board[i][k] == 0) continue;
				if (st.size() == 0) st.push({ board[i][k], 0 });
				// 만약 숫자가 같고, 통합이 안되었다면 통합
				else if (st.top().first == board[i][k] && st.top().second == 0) {
					st.pop(); st.push({ board[i][k] * 2,1 });
				}
				// 통합이 안된다면 그냥 넣기
				else {
					st.push({ board[i][k],0 });
				}
			}

			while (st.size() != n) st.push({ 0,0 });

			// 다시 채워넣기
			for (int i = n - 1; i >= 0; i--) {
				if (st.size()) {
					board[i][k] = st.top().first; st.pop();
				}
				else
					board[i][k] = 0;

				maximum = max(maximum, board[i][k]);
			}
		}
	}
	// 아래쪽으로 옮기기
	else if (dir == 3) {
		for (int k = 0; k < n; k++) {
			stack<pair<int, bool>> st; // 들어간 숫자, 이미 통합 되었는지
			for (int i = n - 1; i >= 0; i--) {
				if (board[i][k] == 0) continue;
				if (st.size() == 0) st.push({ board[i][k], 0 });
				// 만약 숫자가 같고, 통합이 안되었다면 통합
				else if (st.top().first == board[i][k] && st.top().second == 0) {
					st.pop(); st.push({ board[i][k] * 2,1 });
				}
				// 통합이 안된다면 그냥 넣기
				else {
					st.push({ board[i][k],0 });
				}
			}

			while (st.size() != n) st.push({ 0,0 });

			for (int i = 0; i <= n - 1; i++) {
				if (st.size()) {
					board[i][k] = st.top().first; st.pop();
				}
				else
					board[i][k] = 0;


				maximum = max(maximum, board[i][k]);
			}
		}
	}


	//다음에 블록 어떻게 옮길지
	for (int i = 0; i < 4; i++) {
		f(i, cnt + 1, maximum,board);
	}

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> board[i][k];
		}
	}

	for(int i=0; i<4; i++)
		f(i,0, 0, board);

	cout << ans;
	return 0;
}