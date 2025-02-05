#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


int level[1001];
int parent[1001];
bool is_man[1001];
int n, m;
int ans;
int total_node;

priority_queue <tuple<int,int,int>> pq; // 거리, 번호, 번호

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    if(level[a] < level[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    parent[b] = a;
    
    if(level[a]==level[b]) level[a]++;
}

int main(){
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        char tmp; cin >> tmp;
        if(tmp == 'M') is_man[i] = true;
        parent[i] = i;
        level[i] = 1;
    }
    
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        int d; cin >> d;
        
        if(is_man[a] == is_man[b]) continue;
        
        pq.push(make_tuple(-d,a,b));
    }


    while(pq.size()){
        auto tmp = pq.top(); pq.pop();
        int d = -get<0>(tmp);
        int a = get<1>(tmp);
        int b = get<2>(tmp);
        
        a = find(a);
        b = find(b);
    
        if(a == b) continue;
        
        merge(a,b);
        ans += d;
        total_node++;

    }
    
    cout << ((total_node!=n-1) ? -1 : ans);
    
    return 0;
}