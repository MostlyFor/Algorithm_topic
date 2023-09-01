#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;


int ans = 1e9;

int board[20][20];
int n;

void f(vector<int> teamA,int smallest) {
    if (teamA.size() == n/2) {
        int scoreA = 0, scoreB = 0;
        vector<bool> is_teamB(n, 1);
        for (int i = 0; i < teamA.size(); i++) {
            is_teamB[teamA[i]] = 0;
            for (int j = 0; j < i; j++) {
                scoreA += board[teamA[i]][teamA[j]];
                scoreA += board[teamA[j]][teamA[i]];
            }
        }

        vector<int> teamB;
        for (int i = 0; i < n; i++)
            if (is_teamB[i]) teamB.push_back(i);

        for (int i = 0; i < teamB.size(); i++) {
            for (int j = 0; j < i; j++) {
                scoreB += board[teamB[i]][teamB[j]];
                scoreB += board[teamB[j]][teamB[i]];
            }
        }
        
        ans = min(ans, abs(scoreA - scoreB));

        return;
    }

    for (int i = smallest; i < n; i++) {
        teamA.push_back(i);
        f(teamA, i + 1);
        teamA.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    vector<int> teamA;
    f(teamA, 0);

    cout << ans;

    return 0;
}