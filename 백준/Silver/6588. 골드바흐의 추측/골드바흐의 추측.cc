#include <iostream>
#include <vector>
using namespace std;

bool is_not_prime[1000001];
vector<int> prime_number;


// 짝수 x -> "x = a + b"
void solve(int x){
    
    for(auto a : prime_number){
        if(x - a < 0) break;
        if(is_not_prime[x - a] == false){
            cout << x << " = " << a << " + " << x-a << '\n';
            return;
        }
    }
    
    cout << "Goldbach's conjecture is wrong.";
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=2; i<1000001; i++){
        if(is_not_prime[i]) continue;
        prime_number.push_back(i);
        if(i > 10000) continue;
        for(int j = i * i; j < 1000001; j+=i){
            is_not_prime[j] = true;
        }
    }
    
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        solve(n);
    }
    
    
    
    return 0;
}