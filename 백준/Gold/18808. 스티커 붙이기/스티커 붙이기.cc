#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int notebook[41][41];
int block[41][41];

int r, c;

void input(){
    cin >> n >> m >> k;
}


void test_notebook(){
    cout << "노트북 테스트" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << notebook[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}


void test_block(){
    cout << "블록 테스트" << '\n';
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << block[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            block[i][j] = 0;
        }
    }
    
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> block[i][j];
        }
    }
}


bool is_match(int x, int y){
    
    if(x + r > n || y + c > m) return false;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(notebook[x+i][y+j]==1 && block[i][j] == 1) return false;
        }
    }
    
    return true;
}


void rotate(){
    
    vector<vector<int>> tmp(max(r,c), vector<int>(max(r,c), 0));
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            tmp[j][r-1-i] = block[i][j];
        }
    }
    
    int tmp2 = r;
    r = c;
    c = tmp2;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            block[i][j] = tmp[i][j];
        }
    }

}

void push(int x, int y){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            
            if(block[i][j]) notebook[x+i][y+j] = block[i][j];
        }
    }
}

void solve(){
    for(int cnt=0; cnt<4; cnt++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(is_match(i ,j)) {
                    push(i, j);
                    return;
                }
            }
        }
        rotate();
    }
    
}

void output(){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans += notebook[i][j];
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    while(k--){
        init();
        solve();
        // test_notebook();
    }
    
    output();
    
    return 0;
}