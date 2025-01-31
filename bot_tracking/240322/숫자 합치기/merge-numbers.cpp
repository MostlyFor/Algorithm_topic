#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main() {
    int n; cin >> n;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int tmp; cin >> tmp;
        pq.push(-tmp);
    }
   
    int ans = 0;
    while(pq.size()!=1){
        int tmp = pq.top(); pq.pop();
        int tmp2 = pq.top(); pq.pop();

        ans += tmp + tmp2;

        pq.push(tmp+tmp2);
    }

    cout << -ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}