#include <string>
#include <vector>
#include <iostream>

using namespace std;
string answer = "";

// 1.d , 2.l , 3. r, 4. u

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char direction[4] = {'d','l','r','u'};

void f(string ans, int n, int m, int x, int y, int r, int c, int k){
    if(answer != "") return; // 1. 정답이 나왔으면 끝
    int dist = abs(r-x) + abs(c-y); // 남은거리
    if(dist > k) return; // 2. 못가는 거리면 끝
    // cout << dist << ' ' << k - dist << ' ';
    if( (k - dist) % 4 != 0 && (k - dist) % 2 != 0) return; // 3. 남은 거리가 2의 배수이거나 4의 배수가 아니면 끝
    
    if(k == 0){
        answer = ans;
        return;
    }
    
    for(int dir=0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        f(ans + direction[dir], n, m, nx, ny, r, c, k-1);
    }
    
    cout << '?' << '\n';
}


string solution(int n, int m, int x, int y, int r, int c, int k) {

    
    f("", n, m, x, y, r, c, k);
    if(answer == "") answer = "impossible";
    return answer;
}