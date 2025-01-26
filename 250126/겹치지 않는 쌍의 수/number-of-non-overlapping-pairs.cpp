#include <iostream>
using namespace std;

int arr[5000];

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        while(x--) {
            int tmp; cin >> tmp;
            arr[i] = arr[i] | (1 << tmp);
        }
    }
    
    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((arr[i] & arr[j]) == 0) ans++;
        }
    }

    cout << ans;
    return 0;
}