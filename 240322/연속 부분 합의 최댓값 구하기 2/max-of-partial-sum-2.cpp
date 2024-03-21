#include <iostream>
using namespace std;
int arr[100000];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    int l=0,r=0;
    int ans = 0;
    int sum = 0;
    // r 은 다음에 계산할 값
    while(r < n){
        sum += arr[r++];

        // sum이 음수가 되면 그 이후부터 계산
        if(sum < 0) {
            l = r;
            sum = 0;
        }
        else {
            ans = max(sum, ans);    
        }
        
    }

    cout << ans;

    return 0;
}