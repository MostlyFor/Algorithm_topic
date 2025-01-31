#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;


int n, k;

vector<long long> arr(1001,0);

int main() {
    int n; cin >> n;
    // 0 -> 6 -> 18 -> 36 -> 60
    n--;
    int cnt = 1;
    int limit = 0;
    int step = 1;
    while (n > limit) {
        cnt++;
        limit += step * 6;
        step++;
    }
    

    cout << cnt;
    


    return 0;
}