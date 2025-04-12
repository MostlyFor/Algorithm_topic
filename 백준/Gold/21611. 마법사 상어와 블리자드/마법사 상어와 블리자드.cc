#include <iostream>
#include <vector>
using namespace std;

int n, m; // m은 마법의 방향
int board[49][49];
int turn;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int sx;
int sy;

int b1, b2, b3;

void input(){
    cin >> n >> m;
    
    sx = n/2;
    sy = n/2;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

void test_board(){
    cout << "test_board" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void test_board(int board[49][49]){
    cout << "test_board" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

vector<int> get_arr(){
    vector<int> arr; // 상어와 가까운 구슬 순서대로 킵
    // 1 1 2 2 3 3 4 4
    // 왼쪽 아래 오른쪽 위
    int dx2[4] = {0,1,0,-1};
    int dy2[4] = {-1,0,1,0};
    
    int hx = sx;
    int hy = sy;
    int dir = 0;
    
    for(int cnt = 1; cnt < n; cnt++){
        int loop_cnt = 2;
        if(cnt == n-1) loop_cnt = 3;
        
        for(int k=0; k<loop_cnt; k++){
            // 좌상단
            for(int i=0; i<cnt; i++){
                hx = hx + dx2[dir];
                hy = hy + dy2[dir];
                if(board[hx][hy]) arr.push_back(board[hx][hy]);
            }
            dir = (dir+1) % 4;
        }
    }
    return arr;
}

void get_it_done(vector<int> arr){ // 구슬 땡겨서 맞춰주기
    int tmp[49][49];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = 0;
            board[i][j] = 0;
        }
    }
    
    int dx2[4] = {0,1,0,-1};
    int dy2[4] = {-1,0,1,0};
    
    int hx = sx;
    int hy = sy;
    int dir = 0;
    int idx = 0;
    
    for(int cnt = 1; cnt < n; cnt++){
        int loop_cnt = 2;
        if(cnt == n-1) loop_cnt = 3;
        
        for(int k=0; k<loop_cnt; k++){
            for(int i=0; i<cnt; i++){
                if(idx == arr.size()) break;
                hx += dx2[dir];
                hy += dy2[dir];
                tmp[hx][hy] = arr[idx++];
            }
            dir = (dir+1) % 4;
        }
    }
    
    
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void output(){
    cout << 1 * b1 + 2 * b2 + 3 * b3 << '\n';
}

vector<int> g(vector<int> arr){
    
    while(1){
        vector<int> arr2(arr.size(), 1); // 나를 포함해서 이전과 같은 개수
        vector<int> tmp; // 새로 옮겨질 애
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == arr[i-1]) arr2[i] = arr2[i-1]+1;
        }
        
        
        for(int i=arr.size()-1; i>=0; i--){
            if(arr2[i] >= 4){
                int cnt = arr2[i]; // 앞으로 cnt개 지워야함
                while(cnt--){
                    if(arr[i] == 1) b1++;
                    if(arr[i] == 2) b2++;
                    if(arr[i] == 3) b3++;
                    arr2[i] = 0;
                    i--;
                }
                i++;
            }
        }

        
        for(int i=0; i<arr.size(); i++){
            if(arr2[i]) tmp.push_back(arr[i]);
        }
        
        if(arr.size() == tmp.size()) break;
        arr = tmp;
    }
    
    return arr;
}

vector<int> f(vector<int> arr){
    
    vector<pair<int,int>> res;
    int number = arr[0];
    int cnt =1;
    
    for(int i=1; i<arr.size(); i++){
        if(arr[i] == arr[i-1]){
            cnt++; 
        }
        
        else if(arr[i] != arr[i-1]){
            res.push_back({cnt, number});
            number = arr[i];
            cnt = 1;
        }
    }
    
    res.push_back({cnt, number});
    
    
    vector<int> arr2;
    
    for(auto x : res){
        arr2.push_back(x.first);
        arr2.push_back(x.second);
    }
    
    return arr2;
    
}

int main(){
    input();
    
    while(m){
        turn++;
        if(turn == m+1) break;
        int a, d; cin >> d >> a;
        d--;
        
        // 1. 구슬 제거
        for(int i=1; i<=a; i++){
            int nx = sx + i * dx[d];
            int ny = sy + i * dy[d];
            
            board[nx][ny] = 0;
        }
        
        // 2. 구슬 1차원 배열로 바꾸기
        vector<int> arr = get_arr();
        if(arr.size() == 0) break;
        
        // test_board();
        
        // 3. 구슬 폭팔 
        arr = g(arr); 
        
        // 4. 구슬 복제 
        if(arr.size() == 0) break;
        arr = f(arr);
        
        // 5. 구슬 다시 땡겨주기
        if(arr.size() == 0) break;
        get_it_done(arr);
        
        //test_board();
        
    }
    
    output();
    
    return 0;
}