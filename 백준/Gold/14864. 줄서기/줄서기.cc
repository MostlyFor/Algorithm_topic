#include <iostream>
using namespace std;

int arr[100001];
int used[100001];
int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) arr[i] = i;
    
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        arr[a]++;
        arr[b]--;
    }
    
    bool is_pos = true;
    for(int i=1; i<=n; i++) {
        if(used[arr[i]] == true) is_pos=false;
        used[arr[i]] = 1;
    }
    
    if(is_pos){
        for(int i=1; i<=n; i++) cout << arr[i] << ' ';
    }
    else cout << -1;
    return 0;
}