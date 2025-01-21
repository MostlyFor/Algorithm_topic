#include <iostream>
#include <vector>
using namespace std;

int T;

vector<int> fibo;

void solve(int x){
    vector<int> arr;
    
    for(int i = fibo.size()-1; i>=0; i--){
        if(fibo[i] <= x) {
            x -= fibo[i];
            arr.push_back(fibo[i]);
        }
    }
    
    for(int i=arr.size()-2; i>=0; i--){
        cout << arr[i] << ' ';
    }
}

int main(){
    cin >> T;
    
    // 피보나치 수 구하기
    fibo.push_back(0);
    fibo.push_back(1);
    
    while(fibo.back() < 1000000000){
        int n = fibo.size();
        fibo.push_back(fibo[n-1] + fibo[n-2]);
    }
    
    for(int i=0; i<T; i++){
        int x; cin >> x;
        
        solve(x);
        cout << '\n';
    }
    
    
    
    return 0;
}