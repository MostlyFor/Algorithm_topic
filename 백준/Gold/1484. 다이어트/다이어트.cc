#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main(){
    int G; cin >> G;
    
    for(int i=1; i<G; i++){
        if(G % i == 0){
            int x = i;
            int y = G / i;
            
            if(i >= y) continue;
            
            if((y - i)%2 == 0){
                arr.push_back((y - i) / 2 + i);
            }
        }
    }
    
    
    sort(arr.begin(), arr.end());
    if(arr.size() == 0) {cout << -1 << '\n'; return 0;}
    
    for(auto k : arr) cout << k << '\n';
    
    return 0;
}