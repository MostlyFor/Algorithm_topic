#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans[3];
long long best_score = 1e10;
long long arr[5001];

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr + n);
    
    for(int i=0; i<n; i++){
        // arr[i]를 사용했을 때의 최적
        int left = i + 1;
        int right = n - 1;
        
        while(left < right){
            long long score = arr[i] + arr[left] + arr[right];
            
            // 최저 점수라면 값 갱신
            if(abs(score) < best_score){
                best_score = abs(score);
                ans[0] = arr[i];
                ans[1] = arr[left];
                ans[2] = arr[right];
            }
            
            if(score > 0) right--; // 0보다 크면 값을 줄여봐야 함
            else if(score < 0) left++; // 0보다 작으면 값 줄어봐야함
            else break;
        }
    }
    
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}