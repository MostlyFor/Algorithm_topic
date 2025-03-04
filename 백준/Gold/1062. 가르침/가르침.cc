#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> arr;
int none = 0;
int all = -1;
int ans = 0; // k개의 글자를 알 때 읽을 수 있는 최대 단어 수


int cnt = 0;

void f(int st, int k, int vocab){
    if(k == 0 || st == 26){
        
        int tmp_ans = 0;
        for(int s : arr){
            if(s == (vocab & s)) tmp_ans++;
        }
        ans = max(ans, tmp_ans);
        return;
    }
    
    
    for(int i=st; i<26; i++){
        if((vocab & (1 << i)) == (1 << i)) continue;
        if((none & (1 << i)) == 0) {
            f(26, k, vocab);
            continue;
        }
        
        vocab |= (1 << i);
        f(i+1, k-1, vocab);
        vocab ^= (1 << i);
    }
}


int main(){
    cin >> n >> k;
    
    // 26 C 7 => k가 13일 경우가 최대고 풀 순있을 것 같다. 시간복잡도 상당
    // 1. 어디에도 쓰이지 않는 글자는 애초에 제외해도 된다.
    // 2. 항상 쓰이는 글자는 학습 확정
    // 3. 글자가 k개 이상 쓰이는 단어는 제외
    
    for(int i=0; i<n; i++){
        string s; cin >> s;
        int tmp = 0;
        
        for(auto ch : s){
            tmp |= (1 << (ch-'a'));
        }
        
        int cnt_tmp = tmp;
        int cnt = 0;
        while(cnt_tmp){
            if(cnt_tmp % 2) cnt++;
            cnt_tmp /= 2;
        }
        
        if(cnt > k) continue;
        
        arr.push_back(tmp);
        all &= tmp;
        none |= tmp;
    }
    
    int vocab = all;
    
    while(all){
        if(all % 2) k--;
        all /= 2;
    }
    
    if(k < 0) { cout << '0'; return 0;}
    
    f(0, k, vocab);
    
    cout << ans;
    
    return 0;
}