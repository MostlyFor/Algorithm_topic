#include<iostream>
#include<string.h>
using namespace std;

int map[67][67];

bool samenum(int x, int y,int n){
    if(n == 1){
        cout << map[x][y];
        return true;
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(map[x+i][y+j] != map[x][y]) return false; 
        }
    
    cout << map[x][y];
    
    return true;
}



void rec(int x, int y,int n){
    
    if(samenum(x,y,n)) return;
    
    n /=2;
    cout << '(';
    rec(x,y,n);
    rec(x, y + n, n);
    rec(x+n,y,n);
    rec(x+n,y+n,n);
    cout << ')';
}

int main(){
    //1. 초기화
    memset(map,0,sizeof(map));
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string s = "";
        cin >> s;
        for(int j=0; j<N; j++)
            map[i][j] = s[j]-'0';
    }
    rec(0,0, N);
    
    return 0;
}