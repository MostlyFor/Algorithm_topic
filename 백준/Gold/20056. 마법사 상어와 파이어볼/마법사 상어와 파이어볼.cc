#include <iostream>
#include <vector>
using namespace std;

struct Fb{
    int x, y;
    int m;
    int d;
    int s;
};

int n, m, k; // n : 맵 크기, m : 초기 fireball, k : 명령 수
vector<Fb> fbs;

bool in_range(int x, int y){
    return 0<= x && 0 <= y && x < n && y < n;
}

void input(){
    cin >> n >> m >> k;
    
    for(int i=0; i<m; i++){
        int a, b, c, d, e;
        cin >>a >> b >> c >> d >>e;
        a--;b--;
        Fb tmp;
        tmp.x =a;
        tmp.y =b;
        tmp.m = c;
        tmp.s = d;
        tmp.d = e;
        fbs.push_back(tmp);
    }
    
    
}
void output(){
    long long ans = 0;
    for(int idx=0; idx<fbs.size(); idx++){
        ans += fbs[idx].m;
    }
    cout << ans << '\n';
}

void test_fbs(vector<Fb> fbs){
    for(int idx=0; idx < fbs.size(); idx++){
        cout << fbs[idx].x << ' ' << fbs[idx].y << ' ' << fbs[idx].m << ' ' << fbs[idx].s << ' ' << fbs[idx].d << ' ' << '\n';
    }
    cout << '\n';
}

void solve(){
    
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    // 보드에 모든 파이어볼 인덱스 넣기
    vector<int> board[50][50];
    vector<Fb> new_fbs;
    
    
    // 1. 파이어볼 모두 이동
    for(int idx=0; idx<fbs.size(); idx++){
        // cout << k << "???" << '\n';
        int hx = fbs[idx].x;
        int hy = fbs[idx].y;
        int m = fbs[idx].m;
        int d = fbs[idx].d;
        int s = fbs[idx].s;
        if(m == 0) continue;
        
        int nx = ((hx + dx[d] * s) % n + n) % n;
        int ny = ((hy + dy[d] * s) % n + n) % n;
        
        board[nx][ny].push_back(idx);
        // cout << nx << ' ' << ny << '\n';
    }
    
    // 2. 합쳐진 파이어볼 처리
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 하나라면 그대로 
            if(board[i][j].size() == 1){
                new_fbs.push_back(fbs[board[i][j][0]]);
                new_fbs.back().x = i;
                new_fbs.back().y = j;
            }
            
            // 2개 이상의 경우 
            if(board[i][j].size() > 1){
                int total_mess = 0;
                int total_velocity = 0;
                bool is_all_odd = true;
                bool is_all_even = true;
                for(int h=0; h<board[i][j].size(); h++){
                    total_mess += fbs[board[i][j][h]].m;
                    total_velocity += fbs[board[i][j][h]].s;
                    if(fbs[board[i][j][h]].d % 2 == 1) is_all_even = false;
                    if(fbs[board[i][j][h]].d % 2 == 0) is_all_odd = false;
                }
                
                // 4개 만들기
                for(int new_idx = 0; new_idx<4; new_idx ++){
                    Fb tmp;
                    tmp.x = i;
                    tmp.y = j;
                    tmp.m = total_mess / 5;
                    tmp.s = total_velocity / board[i][j].size();
                    if(is_all_odd || is_all_even){
                        tmp.d = new_idx * 2;
                    }
                    else tmp.d = new_idx * 2 + 1;
                    
                    new_fbs.push_back(tmp);
                }
            }
        }
    }
    // test_fbs(fbs);
    // 3. 파이어볼 다시 관리
    fbs = new_fbs;
    // test_fbs(new_fbs);
}
int main(){
    input();
    while(k--){
        solve();
    }
    output();
    return 0;
}