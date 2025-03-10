#include <iostream>
using namespace std;

int n;
int def[8];
int att[8];

int ans = 0;

void f(int idx, int get){
    if(idx == n || get == n-1){ // 더 이상 깰 계란이 없는 경우 
        ans = max(ans, get);
        return;
    }
    
    if(def[idx] <= 0){
        f(idx+1, get);
        return;
    }
    
    for(int i=0; i<n; i++){
        if(i == idx || def[i] <= 0) continue;
        
        // idx 계란으로 i 계란 공격
        def[idx] = def[idx] - att[i];
        def[i] = def[i] - att[idx];
        
        if(def[idx] <= 0) get++;
        if(def[i] <= 0) get++;
        
        f(idx+1, get);
        
        if(def[idx] <= 0) get--;
        if(def[i] <= 0) get--;
        
        def[idx] = def[idx] + att[i];
        def[i] = def[i] + att[idx];
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> def[i];
        cin >> att[i];
    }
    
    f(0, 0);
    
    cout << ans << '\n';
    
    return 0;
}