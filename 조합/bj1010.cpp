#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


// 시간복잡도 : O(b * a) : 
// 공간복잡도 : O(b * a) :

int dp[30][30];

// nCk = n-1Ck + n-1Ck-1
int f(int b, int a) {
    if (a == 0) return 1;
    if (a == b) return 1;
    
    if(!dp[b][a])
        dp[b][a] =  f(b - 1, a) + f(b - 1, a - 1);

    return dp[b][a];
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << f(b, a) << '\n';
    }

    return 0;
}

