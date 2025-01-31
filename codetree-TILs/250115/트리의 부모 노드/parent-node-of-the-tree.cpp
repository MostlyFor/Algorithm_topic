#include <iostream>
using namespace std;

int n;
int parents[100001];

void input(){
    cin >> n;

    parents[1] = 1;

    for(int i=1; i<n; i++){
    
        int a, b; cin >> a >> b;

        if(parents[a] == 0){
            parents[a] = b;
        }

        else if(parents[b] == 0){
            parents[b] = a;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    input();
    
    for(int i=2; i<=n; i++){
        cout << parents[i] << '\n';
    }
    return 0;
}