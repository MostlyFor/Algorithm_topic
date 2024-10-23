#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int arr[4][4000];

unordered_map<int,int> hmap;

int main(){
    
    
    int n; cin >> n;
    hmap.reserve(n * n);  // N^2개의 값을 저장할 수 있도록 공간 예약
    
    for(int i=0; i<n; i++){
        int a, b, c, d; cin >> a >> b >> c >>d;
        arr[0][i] = a;
        arr[1][i] = b;
        arr[2][i] = c;
        arr[3][i] = d;
    }
    
    
    // O(N^2)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(hmap.find(arr[0][i] + arr[1][j]) == hmap.end())
                hmap.insert({arr[0][i] + arr[1][j],1});
            else hmap[arr[0][i] + arr[1][j]] += 1;
        }
    }
    
    
    
    long long ans = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(hmap.find( -(arr[2][i] + arr[3][j]) ) != hmap.end())
                ans += hmap[-(arr[2][i] + arr[3][j])];
        }
    }
    
    cout << ans;
    
    return 0;
}