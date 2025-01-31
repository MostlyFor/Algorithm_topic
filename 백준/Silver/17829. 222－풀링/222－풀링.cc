#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[1024][1024];


int f(int a, int b, int c, int d){
    if(a+2 == c && b+2 == d){
        vector<int> arr;
        arr.push_back(board[a][b]);
        arr.push_back(board[a+1][b]);
        arr.push_back(board[a][b+1]);
        arr.push_back(board[a+1][b+1]);
        sort(arr.begin(), arr.end());
        return arr[2];
    }
    
    
    vector<int> arr;
    arr.push_back(f(a, b, (a+c)/2, (b+d)/2));
    arr.push_back(f(a, (b+d)/2, (a+c)/2, d));
    arr.push_back(f((a+c)/2, b, c, (b+d)/2));
    arr.push_back(f((a+c)/2, (b+d)/2, c, d));
    sort(arr.begin(), arr.end());
    return arr[2];
}



int main(){
    int n; cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    
    cout << f(0, 0, n, n);
    
    return 0;
}