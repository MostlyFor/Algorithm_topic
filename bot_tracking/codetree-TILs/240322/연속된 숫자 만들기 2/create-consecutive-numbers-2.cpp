#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(3,0);
int main() {
    cin >> arr[0] >> arr[1] >> arr[2];
    int cnt =0;
    while(1){
        sort(arr.begin(), arr.end());
        if(arr[0]+1 == arr[1] && arr[1] + 1 == arr[2]) break;
        
        // 짧은 구간으로 이동
        int len1 = arr[1] - arr[0];
        int len2 = arr[2] - arr[1];

        if(len1 ==1) len1 = 2e9;
        if(len2 ==1) len2 =2e9;
        if(len1 >= len2){
            arr[0] = (arr[2] + arr[1])/2;
        }
        else{
            arr[2] = (arr[0] + arr[1])/2;
        }
        cnt++;
    }

    cout << cnt;

    return 0;
}