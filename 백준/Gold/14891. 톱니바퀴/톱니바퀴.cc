#include <iostream>
#include <deque>
using namespace std;

deque<int> state[4];
int k;

void input(){
    for(int i=0; i<4; i++){
        string tmp;
        cin >> tmp;
        for(auto ch : tmp) state[i].push_back(ch=='1');
    }
    
    cin >> k;
}

void f(int t, int d, bool moved[]){
    moved[t] = 1;
    
    // 왼쪽이랑 방향이 같은 경우
    if(t-1 >= 0 && moved[t-1] == 0){
        if(state[t][6] != state[t-1][2]){ // 방향이 다른 경우
            f(t-1, d * -1, moved);
        }
    }
    
    // 오른쪽 톱니 체크
    if(t+1 < 4 && moved[t+1] == 0){
        if(state[t][2] != state[t+1][6]){ // 방향이 다른 경우
            f(t+1, d * -1, moved);
        }    
    }
    
    if(d == 1){ // 시계 방향
        int tmp = state[t].back();
        state[t].pop_back();
        state[t].push_front(tmp);
    }
    
    if(d == -1){ // 반시계 방향
        int tmp = state[t].front();
        state[t].pop_front();
        state[t].push_back(tmp);
    }
}


void test(int n){
    cout << n+1 << "번 톱니:" << '\n';
    for(auto s : state[n]){
        cout << s << ' ';
    }
    
    cout << '\n';
}


int main(){
    input();
    
    while(k--){
        int t, d; cin >> t >> d;
        t--;
        bool moved[4] = {0,0,0,0};
        f(t, d, moved);
        // test(0);
        // test(1);
        // test(2);
        // test(3);
    }
    
    int ans = 0;
    ans += 1 * state[0][0];
    ans += 2 * state[1][0];
    ans += 4 * state[2][0];
    ans += 8 * state[3][0];
    cout << ans << '\n';
    
    return 0;
}