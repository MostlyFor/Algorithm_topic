#include <iostream>
using namespace std;

int T;
int x1, y1, x2, y2;
int n;
int ans = 0;

void init(){
    ans = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    
    for(int i=0; i<n; i++){
        int a, b, r; cin >> a >> b >> r;
        if((x1-a)*(x1-a) + (y1-b)*(y1-b) < r * r && (x2-a)*(x2-a) + (y2-b)*(y2-b) < r * r) continue;
        if((x1-a)*(x1-a) + (y1-b)*(y1-b) < r * r) ans++;
        if((x2-a)*(x2-a) + (y2-b)*(y2-b) < r * r) ans++;
    }
    
    
}

int main(){
    cin >> T;
    while(T--){
        init();
        cout << ans << '\n';
    }
    return 0;
}