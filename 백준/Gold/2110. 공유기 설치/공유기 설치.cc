#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[200001]; // 집 사이의 거리 

// 1 2 4 8 9
// o x o x o

// 거리가 x 이하면 공유기 설치 x

bool pos(int x){
    int pre = arr[0]; // 이전 공유기 설치 위치
    int cnt = c-1; // 설치해야 하는 공유기 수
    
    for(int i=1; i<n; i++){
        if(arr[i] - pre < x) continue; // 거리가 x 이하면 설치 x
        else{
            cnt--;
            pre = arr[i];
        }
    }
    // cout << (cnt<=0) << '\n';
    return (cnt <= 0);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> c;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int s = 0; // 가능한 값
    int e = arr[n-1] + 100; // 불가능한 값
    
    while(s + 1 < e){
        int mid = (s+e)/2;
        // cout << "mid" <<  mid << '\n';
        
        if(pos(mid)) s = mid;
        else e = mid;
    }
    
    cout << s << '\n';
    return 0;
}