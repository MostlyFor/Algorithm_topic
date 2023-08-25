#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w, L;
    cin >> n >> w >> L;

    queue<int> q;
    int q_sum = 0;
    int time = 0;
    vector<int> trucks(n,0);

    for (int i = 0; i < n; i++)
        cin >> trucks[i];
    

    // 현재 몇 번째 트럭인지
    int i = 0;
    while (i != n) {

        // 트럭이 현재 더 올라갈 수 없음
        if (q_sum + trucks[i] > L) {
            q.push(0);
        }

        while (q.size() > w) {
            q_sum -= q.front();
            q.pop();
        }

        // 트럭이 현재 더 올라갈 수 있음
        if(q_sum + trucks[i] <= L){
            q.push(trucks[i]);
            q_sum += trucks[i];
            i++;
        }

        time++;
    }

    cout << time + w;
    return 0;
}