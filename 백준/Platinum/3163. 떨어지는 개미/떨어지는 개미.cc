#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ant_id[100000];
int left_dist[100000];
int position[100000];


int n, L, k;

void solve(){
    cin >> n >> L >> k;
    
    for(int i=0; i<n; i++){
        int pos, id; cin >> pos >> id;
        
        if(id < 0) left_dist[i] = pos;
        else if(id > 0) left_dist[i] = L - pos;
        position[i] = pos;
        ant_id[i] = id;
    }
    
    sort(left_dist, left_dist+n);
    
    int t = left_dist[k-1];
    auto it = std::upper_bound(left_dist, left_dist + n, t-1);
    int k_before = it - left_dist; 
    
    int ans = 1e9;
    int l = 0;
    int r = 0;
    int lw = 0;
    int rw = 0;
    
    for(int i=0; i<n; i++){
        int tx = position[i] + t * (ant_id[i] / abs(ant_id[i]));
        if(tx < 0) l++;
        if(tx > L) r++;
        if(tx == 0) lw++;
        if(tx == L) rw++;
    }
    
    vector<int> list;
    while(lw--) list.push_back(ant_id[l + lw]);
    while(rw--) list.push_back(ant_id[n - 1 - r - rw]);
    
    sort(list.begin(), list.end());
    
    cout << list[k-1 - k_before] << '\n';
    
    
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    
    while(T--){
        solve();
    }
    
    return 0;
}