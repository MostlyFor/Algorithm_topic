#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int, int> p;
#define X first 
#define Y second


// 시간복잡도 O(NlogN)
// 공간복잡도 O(N)

vector<p> pos;

// 임의의 강의는 가장 빨리 넣을 수 있는 곳에 넣는 것이 최선!

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pos.push_back({ a,b });
    }

    sort(pos.begin(), pos.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(pos[0].Y);
    for (int i = 1; i < n; i++) {
        // 넣을 수 있는 경우 
        if(pq.top() <= pos[i].X){
            pq.pop();
            pq.push(pos[i].Y);
        }

        else pq.push(pos[i].Y);
    }

    cout << pq.size();





    return 0;
}