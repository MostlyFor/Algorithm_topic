#include<iostream>
#include<vector>
using namespace std;


int max_side = 0;

void card_count(vector<vector<int>>& map, int k, int& n, int& z, int& p, int target) {

    int r = 0;

    while (r != max_side) {
        r += k;
        int d = 0;
        while (d != max_side) {
                int cnt = 0;
                d += k;
                for (int i = r - k; i < r; i++) {
                    for (int j = d - k; j < d; j++) {
                        if (map[i][j] != target) {
                            cnt++; break;
                        }
                    }
                }

                if (cnt == 0) {
                    if (target == -1) n++;
                    else if (target == 0) z++;
                    else p++;

                    for (int i = r - k; i < r; i++)
                        for (int j = d - k; j < d; j++)
                            map[i][j] = 5;

                    cout << target << " " << k << " " << r << " " << d << '\n';
                }
        }
    }
 

    return;
}


//3. 개수를 세는 함수
void count(vector<vector<int>>& map, int k, int& n, int& z, int& p) {
    if (k == 0) return;

    // 크기가 k*k인 -1,0,1으로만 이루어진 카드 검출
    card_count(map, k, n, z, p, -1);
    card_count(map, k, n, z, p, 0);
    card_count(map, k, n, z, p, 1);

    count(map, k / 3, n, z, p);
    return;
}


int main() {
    // 1. 개수 변수 선언 + map max값 선언
    int n=0, z=0, p=0, k = 0;
    cin >> k;
    max_side = k;


    // 2. vector로 map 받기
    vector<vector<int>> map(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            cin >> map[i][j];

    // 3. 개수를 세는 함수 이용
    count(map, k, n, z, p);

    cout << n << '\n' << z << '\n' << p;
    return 0;
}