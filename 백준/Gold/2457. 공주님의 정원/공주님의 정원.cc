#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;


int start = 301;
int end2 = 0;
int cnt;


int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        int st = 100 * a + b;
        cin >> a >> b;
        int ed = 100 * a + b;
        
        arr.push_back(10000 * st + ed);
    }
    
    sort(arr.begin(), arr.end());
    
    arr.push_back(11301231);
    
    for(int i=0; i<n; i++){
        if(end2>1130) break;
        
        int st = arr[i] / 10000;
        int ed = arr[i] % 10000;
 
        if(st <= start) end2 = max(end2, ed);
        
        else{ // 여기까지의 꽃들이 이전 범위의 꽃들
            start = end2;
            cnt++;
            
            // 다음에 쓰이면 씀
            st = arr[i] / 10000;
            ed = arr[i] % 10000;
            if(st <= start) end2 = max(end2, ed);
        }
        if(end2>1130) cnt++;
    }

    
    
    if(end2 > 1130) cout << cnt;
    else cout << 0;
    
    return 0;
}