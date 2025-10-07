#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n;

int rx, ry;
bool set; // 0: 가로, 1 세로

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visit[101][101][2];

bool in_range(int x, int y){
    return 0<=x && 0<=y && x <n && y< n;
}


bool is_pos(vector<vector<int>> board, int nx, int ny, int nx2, int ny2, int min_x, int min_y, int max_x, int max_y, bool nset){
    
    if(!in_range(nx, ny)) return false;
    if(!in_range(nx2, ny2)) return false;
    if(board[nx][ny] == 1) return false;
    if(board[nx2][ny2] == 1) return false;
    if(board[min_x][min_y] == 1) return false;
    if(board[min_x][max_y] == 1) return false;
    if(board[max_x][min_y] == 1) return false;
    if(board[max_x][max_y] == 1) return false;
    if(visit[nx][ny][nset]) return false;
    
    return true;
}

int solution(vector<vector<int>> board) {
    n = board.size();
    
    queue<tuple<int,int,bool>> q;
    q.push(make_tuple(rx, ry, false));
    visit[rx][ry][false] = 1;
    
    while(q.size()){
        auto h = q.front(); q.pop();
        int hx = get<0>(h);
        int hy = get<1>(h);
        bool hset = get<2>(h);
        int hx2 = hx, hy2 = hy;
        if(hset) hx2 = hx + 1;
        else hy2 = hy+1;
        
        // 순수 이동하는 경우
        for(int dir=0; dir<4; dir++){
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];
            int nx2 = nx, ny2 =ny;
            if(hset) nx2 = nx + 1;
            else ny2 = ny+1;
            
            if(!in_range(nx, ny)) continue;
            if(!in_range(nx2, ny2)) continue;
            if(board[nx][ny] == 1) continue;
            if(board[nx2][ny2] == 1) continue;
            if(visit[nx][ny][hset]) continue;
            
            visit[nx][ny][hset] = visit[hx][hy][hset] + 1;
            q.push(make_tuple(nx,ny,hset));
        }
        
        // 회전하는 경우 - 각각의 경우마다 네 가지
        if(hset){ // 세로의 경우
            // 1. hx, hy가 움직이는 경우
            int nx = hx2;
            int ny = hy2;
            int nx2 = hx2;
            int ny2 = hy2+1;
            bool nset = !hset;
            int min_x = min(min(hx,hx2), min(nx, nx2));
            int min_y = min(min(hy,hy2), min(ny, ny2));
            int max_x = max(max(hx,hx2), max(nx, nx2));
            int max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            // 2. hx, hy가 움직이는 경우
            nx = hx2;
            ny = hy2-1;
            nx2 = hx2;
            ny2 = hy2;
            nset = !hset;
            min_x = min(min(hx,hx2), min(nx, nx2));
            min_y = min(min(hy,hy2), min(ny, ny2));
            max_x = max(max(hx,hx2), max(nx, nx2));
            max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            // 3. hx2, hy2가 움직이는 경우
            nx = hx;
            ny = hy;
            nx2 = hx;
            ny2 = hy+1;
            nset = !hset;
            min_x = min(min(hx,hx2), min(nx, nx2));
            min_y = min(min(hy,hy2), min(ny, ny2));
            max_x = max(max(hx,hx2), max(nx, nx2));
            max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            // 4. hx2, hy2가 움직이는 경우
            nx = hx;
            ny = hy-1;
            nx2 = hx;
            ny2 = hy;
            nset = !hset;
            min_x = min(min(hx,hx2), min(nx, nx2));
            min_y = min(min(hy,hy2), min(ny, ny2));
            max_x = max(max(hx,hx2), max(nx, nx2));
            max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
        }
        
        else{
            // 1. hx, hy가 움직이는 경우
            int nx = hx2;
            int ny = hy2;
            int nx2 = hx2+1;
            int ny2 = hy2;
            bool nset = !hset;
            int min_x = min(min(hx,hx2), min(nx, nx2));
            int min_y = min(min(hy,hy2), min(ny, ny2));
            int max_x = max(max(hx,hx2), max(nx, nx2));
            int max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            // 2. hx, hy가 움직이는 경우
            nx = hx2-1;
            ny = hy2;
            nx2 = hx2;
            ny2 = hy2;
            nset = !hset;
            min_x = min(min(hx,hx2), min(nx, nx2));
            min_y = min(min(hy,hy2), min(ny, ny2));
            max_x = max(max(hx,hx2), max(nx, nx2));
            max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            // 3. hx2, hy2가 움직이는 경우
            nx = hx;
            ny = hy;
            nx2 = hx+1;
            ny2 = hy;
            nset = !hset;
            min_x = min(min(hx,hx2), min(nx, nx2));
            min_y = min(min(hy,hy2), min(ny, ny2));
            max_x = max(max(hx,hx2), max(nx, nx2));
            max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            // 4. hx2, hy2가 움직이는 경우
            nx = hx-1;
            ny = hy;
            nx2 = hx;
            ny2 = hy;
            nset = !hset;
            min_x = min(min(hx,hx2), min(nx, nx2));
            min_y = min(min(hy,hy2), min(ny, ny2));
            max_x = max(max(hx,hx2), max(nx, nx2));
            max_y = max(max(hy,hy2), max(ny, ny2));
            
            if(is_pos(board, nx, ny, nx2, ny2, min_x, min_y, max_x, max_y, nset)){
                visit[nx][ny][nset] = visit[hx][hy][hset] + 1;
                q.push(make_tuple(nx,ny,nset));
            }
            
        }
    }
    
    int answer = 1e9;
    if(visit[n-2][n-1][true]) answer = min(answer, visit[n-2][n-1][true]);
    if(visit[n-1][n-2][false]) answer = min(answer, visit[n-1][n-2][false]);
    
    return answer-1;
}