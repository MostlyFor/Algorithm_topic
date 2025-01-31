#include <iostream>
#include <queue>
using namespace std;

int r, c;
char board[250][250];
bool visited[250][250];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int s, w;

bool is_in(int x, int y){
    return 0<= x && x<r && 0<=y && y<c;
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(visited[i][j]==0 && board[i][j]!='#'){
                queue<int> q;
                q.push(i * 1000 + j);
                
                int tmp_s=0;
                int tmp_w=0;
                if(board[i][j]=='v') tmp_w++;
                if(board[i][j]=='o') tmp_s++;
                visited[i][j] = 1;
                
                while(q.size()){
                    int tmp = q.front(); q.pop();
                    
                    int hx = tmp / 1000;
                    int hy = tmp % 1000;
                    
                    for(int dir=0; dir<4; dir++){
                        int nx = hx + dx[dir];
                        int ny = hy + dy[dir];
                        
                        if(!is_in(nx,ny)) continue;

                        if(visited[nx][ny]) continue;
                        if(board[nx][ny] == '#') continue;
                        
                        if(board[nx][ny]=='v') tmp_w++;
                        if(board[nx][ny]=='o') tmp_s++;
                        
                        q.push(nx * 1000 + ny);
                        visited[nx][ny]=1;
                        
                    }
                }
                
                if(tmp_s > tmp_w) s+=tmp_s;
                else w += tmp_w;
                
            }
        }
    }
    
    cout << s << ' ' << w << '\n';
    
    
    return 0;
}