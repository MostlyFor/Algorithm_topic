#include <iostream>
#include <vector>
using namespace std;

int n;
int board[10][10];
bool visit[10];
int ans =-1;
void f(int lowest, int level){
    if(level == n) {ans = max(ans, lowest); return;}

    for(int i=0; i<n; i++){
        if(visit[i]) continue;
        visit[i] = true;
        int tmp = lowest;
        lowest = min(lowest, board[level][i]);
        f(lowest, level+1);
        lowest = tmp;
        visit[i] = false;
    }
}

int main() {
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    f(1e9, 0);

    cout << ans;

    return 0;
}