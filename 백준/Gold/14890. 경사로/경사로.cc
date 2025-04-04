#include <iostream>
#include <vector>
using namespace std;


int n, l;
int board[101][101];
int ans;

void input(){
    cin >> n >> l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

void test(vector<int> arr, vector<int> board){
    if(arr[0] == 3 && arr[1] == 3 && arr[2] == 2 && arr[3] == 2){
        for(auto x : board) cout << x << ' ';
        cout << '\n';
    }
}

bool h(vector<int>& arr){
    
    vector<int> board(n, 0);
    
    bool is_pos = true;

    for(int i=0; i+1<n; i++){
        // 0. 높이가 2 차이 이상인 경우
        if(abs(arr[i] - arr[i+1]) > 1) {
            is_pos = false; break;
        }
        
        // 1. 높이가 높아진 경우
        if(arr[i] < arr[i+1]){
            if(i-l+1 < 0) is_pos = false;
            else{
                // 경사로를 설치할 수 있는지?
                for(int k=0; k<l; k++){
                    board[i-k]++;
                    if(arr[i] != arr[i-k]) is_pos = false;
                }
            }
        }
        
        
        // 2. 높이가 더 낮아진 경우
        if(arr[i] > arr[i+1]){
            if(i+l >= n) {
                is_pos = false;
            }
            else{
                for(int k=1; k<=l; k++){
                    if(arr[i+1] != arr[i+k]) is_pos = false;
                    board[i+k]++;
                }
            }
        }
    }
    
    for(auto x : board) if(x >1) is_pos =false;
    
    return is_pos;
}

bool f(int r){
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(board[r][i]);
    }
    return h(arr);
}


bool g(int c){
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(board[i][c]);
    }
    return h(arr);
}

int main(){
    input();
    for(int r=0; r<n; r++) if(f(r)) ans++;
    for(int c=0; c<n; c++) if(g(c)) ans++;
    
    cout << ans;
    
    return 0;
}