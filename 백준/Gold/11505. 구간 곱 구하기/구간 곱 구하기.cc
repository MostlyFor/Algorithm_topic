#include <iostream>
using namespace std;

int n, m, k; // 수의 개수, 수의 변경, 구간 곱의 횟수
long long segtree[1000000 * 4 + 5];
long long arr[1000001];

void init_seg(int node, int st, int ed){
    if(st == ed){
        segtree[node] = arr[st];
        return;
    }
    
    int mid = (st + ed) / 2;
    init_seg(node*2, st, mid);
    init_seg(node*2 + 1, mid+1, ed);
    segtree[node] = segtree[node * 2] * segtree[node*2+1] % 1000000007;
    
}

void update(int node, int st, int ed, int idx, int c){
    if(idx < st || ed < idx) return;
    if(st == ed && st == idx){
        segtree[node] = c;
        return;
    }
    int mid = (st + ed) / 2;
    update(node*2, st, mid, idx, c);
    update(node*2+1, mid+1, ed, idx, c);
    segtree[node] = segtree[node * 2] * segtree[node*2+1] % 1000000007;
}

long long get(int node, int st, int ed, int l, int r){
    if(r < st  || l > ed) return 1;
    if(st == ed) return segtree[node];
    if(l<= st && ed <= r) return segtree[node];
    
    int mid = (st + ed) / 2;
    return get(node*2, st, mid, l, r) * get(node*2+1, mid+1, ed, l, r) % 1000000007;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    init_seg(1,1,n);
    
    for(int i=0; i<m+k; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(1,1,n,b,c);
        }
        else{
            cout << get(1, 1, n, b, c) << '\n';
        }
    }
    
    
    return 0;
}