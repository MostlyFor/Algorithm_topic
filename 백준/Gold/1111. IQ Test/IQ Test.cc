#include <iostream>
using namespace std;

int n;
int arr[50];

int main(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    if(n == 1) {cout << 'A'; return 0;}
    if(n==2 && arr[0] != arr[1]) {cout << 'A'; return 0;}
    if(arr[0] == arr[1]){
        bool is_same = true;
        for(int i=0; i<n; i++){
            if(arr[i] != arr[0]) is_same=false;
        }
        
        if(is_same) cout << arr[0];
        else cout << 'B';
        
        return 0;
    }
    
    // a = (x2-x1) / (x1-x0)
    
    int a = (arr[2]-arr[1]) / (arr[1] - arr[0]);
    int b = arr[1] - a * arr[0];
    
    
    for(int i=0; i<n-1; i++){
        if(arr[i+1] != arr[i] * a + b){
            cout << 'B'; return 0;
        }
    }
    
    cout << arr[n-1] * a + b;
    
    
    
    
    return 0;
}