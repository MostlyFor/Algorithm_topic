#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
using namespace std;

vector<vector<int>> matrix;
int n;
long long b;

vector<vector<int>> dot(vector<vector<int>> mat1, vector<vector<int>> mat2) {

    vector<vector<int>> mat_new(n,vector<int>(n,0));

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat_new[i][k] += mat1[i][j] * mat2[j][k];
            }
            mat_new[i][k] %= 1000;
        }
    }

    return mat_new;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    vector<vector<int>> matrix;
    vector<vector<int>> ans(n,vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            tmp.push_back(t);
            ans[i][i] = 1;
        }
        matrix.push_back(tmp);
    }

    while (b != 0) {
        if (b % 2 == 1) {
            ans = dot(ans, matrix);
        }
        matrix = dot(matrix, matrix);
        b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j]%1000 << ' ';
        cout << '\n';
    }

    return 0;
}