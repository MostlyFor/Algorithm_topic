#include <iostream>
#include <vector>
using namespace std;

int n;
int vistied[100001];
vector<int> children[100001];
int dp[100001];

int f(int x){

    for(auto n : children[x]){
        int value = f(n);
        if(value > 0) dp[x] += value;
    }
    
    return dp[x];
}

int main() {
    cin >> n;

    for(int i=2; i<=n; i++){
        int t, a, p; cin >> t >> a >> p;
        int value = a;
        if(t == 0) value *=-1;
        dp[i] = value;
        children[p].push_back(i);
    }

    cout << f(1);

    return 0;
}