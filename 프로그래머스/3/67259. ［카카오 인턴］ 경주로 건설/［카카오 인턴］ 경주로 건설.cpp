#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dp[25][25][4]; // dp로 해당 위치까지 오는 최소 비용 + 방향
int check[25][25];
int n;

bool in_range(int x, int y){
    return 0<=x && 0<=y && x<n && y<n;
}
int dx[4] = {-1,0,1,0}; // 상좌하우
int dy[4] = {0,-1,0,1};


int solution(vector<vector<int>> board) {
    int answer = 0;
    // 직선도로 100원 코너 500원 = 직진하면 100원, 방향 바꾸면 500원
    // 0,0 -> n-1, n-1 까지 가는 최소 비용
    
    n = board.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int dir=0; dir<4; dir++){
                dp[i][j][dir] = 1e9; 
            }
        }
    }
    
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;
    dp[0][0][3] = 0;
    
    
    for(int t=0; t<625; t++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int dir=0; dir<4; dir++){
                    // 일자로 가는 경우 
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(in_range(nx,ny) && board[nx][ny] == 0)
                        dp[nx][ny][dir] = min(dp[nx][ny][dir], dp[i][j][dir] + 100);

                    // 90도 꺾어서 가는 경우 (1)
                    int next_dir = (dir + 1)%4;
                    nx = i + dx[next_dir];
                    ny = j + dy[next_dir];
                    if(in_range(nx,ny) && board[nx][ny] == 0) 
                        dp[nx][ny][next_dir] = min(dp[nx][ny][next_dir], dp[i][j][dir] + 600);

                    // (2)
                    next_dir = (dir + 3)%4;
                    nx = i + dx[next_dir];
                    ny = j + dy[next_dir];
                    if(in_range(nx,ny) && board[nx][ny] == 0)  
                        dp[nx][ny][next_dir] = min(dp[nx][ny][next_dir], dp[i][j][dir] + 600);
                }
            }
        }
    }

//     for(int i=n-1; i>=0; i--){
//         for(int j=n-1; j>=0; j--){
//             for(int dir=0; dir<4; dir++){
//                 // 일자로 가는 경우 
//                 int nx = i + dx[dir];
//                 int ny = j + dy[dir];
//                 if(in_range(nx,ny) && board[nx][ny] == 0)
//                     dp[nx][ny][dir] = min(dp[nx][ny][dir], dp[i][j][dir] + 100);

//                 // 90도 꺾어서 가는 경우 (1)
//                 int next_dir = (dir + 1)%4;
//                 nx = i + dx[next_dir];
//                 ny = j + dy[next_dir];
//                 if(in_range(nx,ny) && board[nx][ny] == 0) 
//                     dp[nx][ny][next_dir] = min(dp[nx][ny][next_dir], dp[i][j][dir] + 600);

//                 // (2)
//                 next_dir = (dir + 3)%4;
//                 nx = i + dx[next_dir];
//                 ny = j + dy[next_dir];
//                 if(in_range(nx,ny) && board[nx][ny] == 0)  
//                     dp[nx][ny][next_dir] = min(dp[nx][ny][next_dir], dp[i][j][dir] + 600);
//             }
//         }
//     }
    

    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             check[i][j] = 1e9;
//         }
//     }
    
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             for(int dir=0; dir<4; dir++){
//                 check[i][j] = min(check[i][j], dp[i][j][dir] + dir+1);
//                 if(board[i][j]) check[i][j] = 1;
//             }
//         }
//     }
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout << check[i][j] << ' ';
//         }
//         cout << '\n';
//     }

    answer = 1e9;
    for(int dir = 0; dir <4; dir++) answer = min(answer, dp[n-1][n-1][dir]);
    
    return answer;
}