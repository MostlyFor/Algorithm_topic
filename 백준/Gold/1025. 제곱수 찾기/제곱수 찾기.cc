#include <iostream>
#include <unordered_map>
using namespace std;
int r, c;
string board[9];
unordered_map<int, int> hmap;


void f(int x, int y, int dx, int dy){
    if(dx == 0 && dy == 0) return;
    
    string s = "";
    int hx = x;
    int hy = y;
    
    while(0<= hx && 0 <= hy && hx < r && hy < c){
        s += board[hx][hy];
        hmap[stoi(s)] = 1;
        hx = hx + dx;
        hy = hy + dy;
    }
}

int main(){
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        cin >> board[i];
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int dx =-9; dx <9; dx++){
                for(int dy=-9; dy <9; dy++){
                    f(i, j, dx, dy);
                }
            }
        }
    }
    
    int ans = -1;
    
    for(int i=0; i*i<=999999999; i++){
        if(hmap[i*i]) ans = max(ans, i*i);
    }
    
    cout << ans;
    
    return 0;
}