#include <iostream>
using namespace std;
int n, m;

int arr[50][50];
int ans = 0;

void click(int x, int y){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[x+i][y+j] = arr[x+i][y+j] ^ 1;
        }
    }
}


int main(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        string str; cin >> str;
        
        for(int j=0; j<m; j++){
            int tmp = str[j] - '0';
            arr[i][j] = tmp;
        }
    }
    
    for(int i=0; i<n; i++){
        string str; cin >> str;
        for(int j=0; j<m; j++){
            int tmp = str[j] - '0';
            arr[i][j] = tmp ^ arr[i][j];
        }
    }

    
    // 위에서부터 내려오면서 1이면 뒤집기
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-2; j++){
            if(arr[i][j]) {
                ans ++;
                click(i, j);
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]){
                cout << -1; return 0;
            }
        }
    }
    cout << ans;
    
    
    return 0;
}