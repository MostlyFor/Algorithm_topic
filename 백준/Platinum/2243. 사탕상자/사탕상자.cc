#include <iostream>
using namespace std;

int n;
int segtree[1000001 * 4 + 5];
int res = 0;

void update(int node, int st, int ed, int b, int c){
    if(!(st <= b && b <= ed)) return; 
    
    if(st == ed && st == b){
        segtree[node] += c;
        return;
    }
    
    segtree[node] += c;
    
    int mid = (st+ed) /2;
    update(node*2, st, mid, b, c);
    update(node*2+1,mid+1, ed, b, c);
}

// b 순위의 사탕을 c개 꺼냄
void get(int node, int st, int ed, int b, int c){
    if(st == ed){
        res = st;
        update(1, 1, 1000000, st, -c);
        return;
    }
    
    int mid = (st+ed) /2;
    if(segtree[node*2] >= b){
        get(node*2, st, mid, b, c);
    }

    else{
        get(node*2+1, mid+1, ed, b - segtree[node*2], c);
    }
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a; cin >> a;
        // 사탕 꺼내는 경우
        if(a == 1){ 
            int b, c; cin >> b;
            c = 1;
            // b 순위의 사탕을 c개 꺼내는
            get(1,1,1000000,b,c);
            cout << res << '\n';
            res = 0;
        }
        // 사탕 넣는 경우
        else{
            int b, c; cin >> b >> c;
            // b 맛의 사탕 c개 넣음
            update(1,1,1000000,b,c);
        }
    }
    return 0;
}