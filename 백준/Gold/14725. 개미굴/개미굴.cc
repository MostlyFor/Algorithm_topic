#include <bits/stdc++.h>
using namespace std;
vector<string> arr;

// 문자열 출력 함수
void f(int idx, int st){
    string base = "--";
    
    int n = arr[idx].size();
    int base_cnt = st / 15;
    
    string stream ="";
    
    while(n > st){
        
        // 출력해야 하는 부분
        for(int i = st + 0; i<st + 15; i++){
            if(arr[idx][i] == '#') break;
            stream += arr[idx][i];
        }
        st += 15;
        
        // -- 개수 채우기
        string base_tmp = "";
        int tmp_i = base_cnt;
        while(tmp_i--) base_tmp += base;
        base_cnt++;
        
        cout << base_tmp << stream << '\n';
        stream = "";
    }
    
    
}

// 몇 번째 문자열에서 어긋나는지
int g(int idx){
    
    string s = arr[idx];
    string s_b = arr[idx-1];
    
    for(int i=0; i<15 * 15; i++){
        if(s[i] != s_b[i]) return i / 15;
    }
    
    return -1;
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    
    for(int i=0; i<n; i++){
        int l; cin >> l;
        
        string word;
        string tmp;
        while(l--){
            cin >> tmp;
            int gap = 15 - tmp.size();
            while(gap--) tmp += "#";
            word+=tmp;
        }
        
        arr.push_back(word);
    }
    
    // O(NlogN * 256)
    sort(arr.begin(), arr.end());
    
    
    // O(N * 256 * 256)
    f(0, 0);
    for(int i=1; i<arr.size(); i++){
        int start_idx = g(i) * 15;
        f(i, start_idx);
    }
    
    return 0;
}