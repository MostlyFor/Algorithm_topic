#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


// 시간복잡도 O(M * a(N)) : a 애커만 함수
// 공간복잡도 O(N)

vector<int> arr;
vector<int> level;

int find(int x) {
    if (x == arr[x]) return x;
    return arr[x] = find(arr[x]);
}


void merge(int b, int c) {
    b = find(b);
    c = find(c);
    
    if (b == c)
        return;

    // b가 깊은 트리 되게 바꿈
    if (level[b] < level[c])
        swap(b, c);

    arr[c] = b;

    if (level[b] == level[c])
        level[b]++;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        arr.push_back(i);
        level.push_back(1);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0) merge(b,c);
        else {
            b = find(b);
            c = find(c);
            if (b == c) cout << "YES"<< '\n';
            else cout << "NO"<<'\n';
        }
    }

    return 0;
}

