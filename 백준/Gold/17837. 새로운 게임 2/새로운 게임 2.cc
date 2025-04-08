#include <iostream>
#include <vector>
using namespace std;

int board[12][12];
int n, k;

// 핀에 대한 정보들
vector<int> pboard[12][12];
vector<pair<int,int>> pin;
vector<int> pin_vector;
int T;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void input(){
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<k; i++){
        int a, b, d; cin >> a >> b >> d;
        a--; b--; d--;
        pin.push_back({a,b});
        pin_vector.push_back(d);
        pboard[a][b].push_back(i);
    }
}

bool in_range(int x, int y){
    return 0<=x && 0<=y && x <n && y<n;
}

void move(int st){
    int hx = pin[st].first;
    int hy = pin[st].second;
    int dir = pin_vector[st];
    // cout << st << "핀 이동 : " << hx << ' ' << hy << ' ' << dir << '\n';
    
    // 1. 한 번에 움직일 말들 넣기
    vector<int> arr; 
    int idx = -1;
    for(int i=0; i<pboard[hx][hy].size(); i++){
        if(pboard[hx][hy][i] == st){
            idx = i;
        }
        if(idx != -1){
            arr.push_back(pboard[hx][hy][i]);
        }
    }
    // 2. 움직인 말들 판에서 제거
    for(int i=0; i<arr.size(); i++){
        pboard[hx][hy].pop_back();
    }
    
    int nx = hx + dx[dir];
    int ny = hy + dy[dir];
    
    if(!in_range(nx, ny) || board[nx][ny] == 2){ // 파란색인 경우
        if(dir == 0) dir =1;
        else if(dir == 1) dir = 0;
        else if(dir == 2) dir = 3;
        else if(dir == 3) dir = 2;
        
        // cout << "변경 전 : " << nx << ' ' << ny << '\n';
        
        nx = hx + dx[dir];
        ny = hy + dy[dir];

        // cout << "변경 후 : " << nx << ' ' << ny << '\n';
        pin_vector[st] = dir; // 핀 방향 바꾸고
        
        if(!in_range(nx, ny) || board[nx][ny] == 2){ // 다시 파란색인 경우 이동 x
            for(int i=0; i<arr.size(); i++){
                int pin_n = arr[i];
                pin[pin_n] = {hx, hy};
                pboard[hx][hy].push_back(pin_n);
            }
            return; // 이동 x
        }
    }
    
    if(board[nx][ny] == 0){ // 흰색인 경우
        for(int i=0; i<arr.size(); i++){
            int pin_n = arr[i];
            pin[pin_n] = {nx, ny};
            pboard[nx][ny].push_back(pin_n);
        }
    }
    
    if(board[nx][ny] == 1){ // 빨간색인 경우
        for(int i=arr.size() -1; i >= 0; i--){
            int pin_n = arr[i];
            pin[pin_n] = {nx, ny};
            pboard[nx][ny].push_back(pin_n);
        }
    }
}

bool is_end(){
    bool is_four = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pboard[i][j].size() >= 4) is_four = true;
        }
    }
    return is_four;
}

void test_pin(){
    for(int i=0; i<k; i++){
        cout << i << "번째 핀 : " << pin[i].first << ' ' << pin[i].second << '\n';
    }
    cout << '\n';
}

void test_pboard(){
    cout << T << "번째 턴" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << pboard[i][j].size() << ' ';
        }
        cout << '\n';
    }
}

void test_stack(int x, int y){
    for(auto h : pboard[x][y]){
        cout << h << ' ';
    }
    cout << '\n';
}
int main(){
    input();
    
    while(1){
        T++;
        if(T== 1001) break;
        for(int i=0; i<k; i++) {
            move(i);
            // test_pboard();
            // test_pin();
            // test_stack(0,2);
            if(is_end()) break;
        }
        if(is_end()) break;
        // break; // if(T==1) break;
    }
    
    if(T==1001) cout << -1;
    else cout << T;
    return 0;
}