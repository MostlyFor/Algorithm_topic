#include <iostream>
using namespace std;

int n;
int expected[1000002]; // expected[i] = x : 다음 수로 i를 기대하는 인덱스 x 
int arr[1000000];
int inc[1000000]; 
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        expected[arr[i]+1] = i;
        inc[i] = 1;
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1) continue;
        int idx = expected[arr[i]]; // arr[i]를 기대하고 있던 idx
        if(i < idx) continue; // 앞에 있다면 제거
        inc[idx]++;
        expected[arr[i]+1] = idx;
        ans = max(ans,inc[idx]);
    }
    
     cout << ((ans == 0) ? n-1 : n - ans) << '\n';
    
    return 0;
}