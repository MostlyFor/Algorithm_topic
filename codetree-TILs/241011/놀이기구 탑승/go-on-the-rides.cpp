#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr[401];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int board[20][20];
int score_board[20][20]; // 인접한 칸 중 친구 수
int bear_board[20][20]; // 인접한 칸 중 비어있는 칸 수



bool is_out(int x, int y){
    return 0 > x || 0 > y || x >= n || y>=n;
}

int main() {
    cin >> n;

    for(int qqq=1; qqq <= n*n; qqq++){
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;

        arr[a].push_back(b);arr[a].push_back(c);arr[a].push_back(d);arr[a].push_back(e);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                score_board[i][j] = 0;
                bear_board[i][j] = 0;
            }
        }

        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]) continue;
                int cnt = 0;
                int bear = 0;

                for(int dir =0; dir<4; dir++){
                    
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    
                    if(is_out(nx,ny)) continue;
                    // cout << nx << ' ' << ny << '\n';

                    if(board[nx][ny] == b || board[nx][ny] == c || board[nx][ny] == d || board[nx][ny] == e) cnt++;
                    if(board[nx][ny] == 0) {
                        bear++;
                    }
                }

                score_board[i][j] = cnt;
                bear_board[i][j] = bear;
            }
        }


        int max_cnt = -1;
        int max_bear = -1;
        int nx = -1;
        int ny = -1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]!=0) continue;
                if(max_cnt < score_board[i][j]){
                    max_cnt = score_board[i][j];
                    max_bear = bear_board[i][j];
                    nx = i; ny = j;
                }
                else if(max_cnt == score_board[i][j]){
                    if(bear_board[i][j] > max_bear){
                        max_bear = bear_board[i][j];
                        nx = i; ny = j;
                    }
                }
            }
        }

        // cout << nx << ' ' << ny << '\n';
        board[nx][ny] = a;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    


    int answer =0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = 0;
            for(int dir =0; dir<4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(is_out(nx,ny)) continue;
                
                for(auto fr : arr[board[i][j]]){
                    if(board[nx][ny] == fr) cnt++;
                }
            }

            if(cnt == 1) answer +=1;
            else if(cnt ==2) answer += 10;
            else if(cnt ==3) answer += 100;
            else if(cnt ==4) answer += 1000;
               
        }
    }

    cout << answer;
    
    
    return 0;
}