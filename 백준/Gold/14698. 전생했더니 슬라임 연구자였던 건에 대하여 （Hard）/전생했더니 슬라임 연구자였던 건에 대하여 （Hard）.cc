#include <iostream>
#include <queue>
using namespace std;


int T;
long long arr[60];

// a b c d 
// ab + abc + abcd

// 6
// 4 5 6
// 20 + 6
// 6 20
// 20 + 6 + 120
// 120

int solve(){
    int n; cin >> n;
    
    priority_queue <long long> pq;
    
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
        pq.push(-arr[i]);
    }
    
    if(n == 1) return 1;
    
    long long ans = 1;
    
    while(pq.size() > 1){
        long long a = -pq.top(); pq.pop();
        long long b = -pq.top(); pq.pop();
        pq.push( - a * b);
        ans = ans * ( (a * b) % 1000000007) % 1000000007;
    }

    
    return ans;
}



int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    
    while(T--){
        cout << solve() << '\n';
    }
    
    
    
    return 0;
}