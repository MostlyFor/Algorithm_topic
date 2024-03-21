#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int board[100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool InRange(int x, int y){
    return 0<=x&&0<=y&&x<n&&y<m;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    board[0][0] = -1;

    int pos = 0;
    while(q.size()){
        auto h = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = h.first + dx[i];
            int ny = h.second + dy[i];
            if(!InRange(nx,ny)) continue;
            if(board[nx][ny]!= 1) continue;
            board[nx][ny] = -1;
            q.push({nx,ny});
            if(nx == n-1 && ny == m-1) pos = 1;
        }
    }

    cout << pos;

    return 0;
}