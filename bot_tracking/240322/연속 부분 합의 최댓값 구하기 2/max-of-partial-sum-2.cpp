#include <iostream>
using namespace std;
int arr[100000];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    int l=0,r=0;
    int ans = -1e9;
    int sum = 0;

    // i 번째 해당하는 블록을 정답으로 가져갈건지 아닌지
    for(int i=0; i<n; i++){
        sum += arr[i];
        ans = max(ans, sum);

        if(sum <0) sum = 0;
        
    }

    cout << ans;

    return 0;
}