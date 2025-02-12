#include <iostream>
using namespace std;

int n, m, r;
int arr[300][300];

// (a,b)를 왼쪽 위, (c,d)를 오른쪽 아래로 하는 행렬 회전
void rotate(int a, int b, int c, int d){
    
    int x = c - a + 1; // 세로
    int y = d - b + 1; // 가로
    
    int tmp = arr[a][b];
    for(int j=0; j<y-1; j++){
        arr[a][b+j] = arr[a][b+j+1];
    }
    
    int tmp2 = arr[c][b];
    for(int i=x-1; i>=1; i--){
        arr[a+i][b] = arr[a+i-1][b];
    }
    arr[a+1][b] = tmp;
    
    tmp = arr[c][d];
    for(int j=y-1; j>=1; j--){
        arr[c][b+j] = arr[c][b+j-1];
    }
    arr[c][b+1] = tmp2;
    
    for(int i=0; i < x-1; i++){
        arr[a+i][d] = arr[a+i+1][d];
    }
    arr[c-1][d] = tmp;
    
}

int main(){
    cin.tie(0);
    cout.tie(0);
    
    // 테두리 (2n + 2m -4)
    cin >> n >> m >> r;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int k = 0;
    while(n-k-k >= 2 && m-k-k >=2){
        int equal = 2*(n - 2*k + m- 2*k -2);
        int remain_rotate = r % equal;
        while(remain_rotate--) rotate(k, k, n-k-1, m-k-1);
        k++;
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}