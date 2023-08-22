#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>

using namespace std;


//시간복잡도 O(1) : 10036

bool is_not_self[10036];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 10000; i++) {
        if (!is_not_self[i]) {
            cout << i << '\n';
        }

        // i번을 생성자로 계산
        int gn = i;
        int k = i;
        while (k) {
            gn += k % 10;
            k /= 10;
        }
        is_not_self[gn] = true;
    }
    
    return 0;
}