#include <iostream>
using namespace std;

long long n, k;

long long pos(long long x){
    long long cnt = 0;
    
    long long st = 1;
    for(long long i=1; i<=n; i++){
        cnt += min(n, x / i);
    }

    return cnt;
}



int main(){
    cin >> n >> k;
    
    long long start = 0; // 정답이 되기엔 작음
    long long end = n * n + 1; // 정답 후보 : K 번째가 되는 최소 수
    
    while(start + 1 < end){
        long long mid = (start + end) / 2;
        long long position = pos(mid);
        //cout << mid << ' ' << position << '\n';
        if(position < k) {
            start = mid;
        } else {
            end = mid; 
        }

    }
    
    cout << end << '\n';

    
    return 0;
}