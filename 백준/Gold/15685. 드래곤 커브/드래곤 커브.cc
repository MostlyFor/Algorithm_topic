#include <iostream>
#include <vector>
using namespace std;

int board[101][101];
int n; 
int dx[4] = {0, -1, 0, 1}; // ㅏ ㅗ ㅓ ㅜ
int dy[4] = {1, 0, -1, 0};

vector<int> arr[11];
int ans;

void test_board(int a,int b,int c, int d);

bool in_range(int x,int y){
    return 0<= x && 0<= y && x<=100 && y<=100;
}

void init(){
    arr[0].push_back(0);
    for(int g=1; g<=10; g++){
        // 원래 방향
        for(int i=0; i<arr[g-1].size(); i++){
            arr[g].push_back(arr[g-1][i]);
        }
        
        // 역순 방향
        for(int i=arr[g-1].size()-1; i>=0; i--){
            arr[g].push_back((arr[g-1][i] + 1) % 4);
        }
    }
}

void input(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        int x, y, d, g; cin >> y >> x >> d >> g;
        
        board[x][y] = 1;
        int nx = x;
        int ny = y;
        
        for(auto dir : arr[g]){
            int new_dir = (dir + d) % 4;
            
            nx = nx + dx[new_dir];
            ny = ny + dy[new_dir];
            
            if(!in_range(nx,ny)) continue;
            board[nx][ny] = 1;
        }
        // test_board(1,2,4,4);
    }
    
    for(int i=0; i+1 <101; i++){
        for(int j=0; j+1 <101; j++){
            if(board[i][j] == 1 && board[i+1][j] == 1 && board[i][j+1] == 1 && board[i+1][j+1] == 1)
                ans++;
        }
    }
}

void test_dragon(){
    cout << "드래곤 테스트" << '\n';
    for(int i=0; i<=3; i++){
        for(auto d : arr[i]) cout << d << ' ';
        cout << '\n';
    }
    cout << '\n';
    
}

void test_board(int a, int b, int c, int d){
    cout << "보드 테스트" << '\n';
    for(int i=a; i<=c; i++){
        for(int j=b; j<=d; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    init(); // 드래곤 커브 만들기
    // test_dragon();
    input();
    cout << ans;
    return 0;
}