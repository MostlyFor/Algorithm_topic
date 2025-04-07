#include <iostream>
#include <vector>
using namespace std;
int r, c;
int m;

int king;
int ans;

vector<pair<int,int>> sharks; // 상어 위치
vector<pair<int,int>> sharks_vector; // 상어 속력, 이동 방향
vector<int> sharks_size;
vector<int> is_alive;

void test_board();

void input(){
    cin >> r >> c >> m;
    
    for(int i=0; i<m; i++){
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        a--; b--; d--;
        sharks.push_back({a,b});
        sharks_vector.push_back({c,d});
        sharks_size.push_back(e);
        is_alive.push_back(1);
    }
    
}

void fishing(){
    int idx = -1;
    int dist = 1e9;
    
    for(int i=0; i<m; i++){
        if(is_alive[i] == 0) continue;
        int hx = sharks[i].first;
        int hy = sharks[i].second;
        
        if(hy != king) continue;
        
        if(dist > hx) {
            idx = i;
            dist = hx;
        }
    }
    
    if(idx == -1) return;
    is_alive[idx] = 0;
    ans += sharks_size[idx];
    
}

bool in_range(int x, int y){
    return 0<= x && 0<= y && x < r && y < c;
}

void move(){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    // 상어 이동 - 여기가 조금 까다로운 부분
    for(int i=0; i<m; i++){
        if(is_alive[i] == 0) continue;
        int hx = sharks[i].first;
        int hy = sharks[i].second;
        
        int ve = sharks_vector[i].first;
        int d = sharks_vector[i].second;
        
        // 벽에 붙어있는 경우
        if(hx == 0 || hy == 0 || hx == r-1 || hy == c-1){
            int nx = hx + dx[d];
            int ny = hy + dy[d];
            
            if(!in_range(nx,ny)){
                if(d==0) d=1;
                else if(d==1) d=0;
                else if(d==2) d=3;
                else if(d==3) d=2;
                
                nx = hx + dx[d];
                ny = hy + dy[d];
            }
            
            hx = nx;
            hy = ny;
            ve--;
        }
        
        // 벽에 붙어있지 않은 경우
        if(d == 0 || d == 1) ve = (ve % ( 2 * r -2) + (2 * r -2)) % ( 2 * r -2) ;
        else if(d == 2 || d == 3) ve = (ve % (2 * c-2)+(2 * c-2)) % (2 * c-2);
        
        
        int nx, ny;
        while(ve){
            ve--;
            nx = hx + dx[d];
            ny = hy + dy[d];
            
            if(!in_range(nx,ny)){
                if(d==0) d=1;
                else if(d==1) d=0;
                else if(d==2) d=3;
                else if(d==3) d=2;
                
                nx = hx + dx[d];
                ny = hy + dy[d];
            }
            
            hx = nx;
            hy = ny;
        }
        
        sharks[i].first = hx;
        sharks[i].second = hy;
        sharks_vector[i].second = d;
        
        
        // test_board();
    }
    
    int board[100][100];
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            board[i][j] = 0;
        }
    }
    
    // 상어 이동 후 겹치면 제거
    for(int i=0; i<m; i++){
        if(is_alive[i] == 0) continue;
        int hx = sharks[i].first;
        int hy = sharks[i].second;
        
        int ss = sharks_size[i];
        board[hx][hy] = max(board[hx][hy], ss);
    }
    
    // 상어 이동 후 겹치면 제거
    for(int i=0; i<m; i++){
        if(is_alive[i] == 0) continue;
        int hx = sharks[i].first;
        int hy = sharks[i].second;
        
        int ss = sharks_size[i];
        if(board[hx][hy] > ss) is_alive[i] = 0;
    }
}

void test_fishing(){
    cout << ans << '\n';
}

void test_board(){
    cout << "상어 이동 테스트" << '\n';
    vector<vector<int>> bd(r, vector<int>(c,0));
    
    for(int i=0; i<m; i++){
        if(is_alive[i] == 0) continue;
        int hx = sharks[i].first;
        int hy = sharks[i].second;
        bd[hx][hy] = i+1;
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << bd[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
}

int main(){
    input();
    
    for(king = 0; king<c; king++){
        fishing();
        // test_fishing(); 
        // test_board();
        move(); // 상어 이동
        // test_board();
    }
    
    cout << ans << '\n';
    
    return 0;
}