#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int n;
vector<string> arr;


void init(){
    cin >> n;
    
    arr.clear();

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        arr.push_back(str);
    }
    
}

bool is_include(){
    for(int i=1; i<n; i++){
        
        if(arr[i-1].size() > arr[i].size()) continue;
        
        
        string tmp;
        int before_length = arr[i-1].size();
        int idx = 0;
        
        while(before_length--) tmp.push_back(arr[i][idx++]);
        
        if(arr[i-1] == tmp)
            return true;
        
    }
        
    return false;
}

int main(){
    cin >> T;
    while(T--){
        init();
        
        sort(arr.begin(), arr.end());
        
        // for(auto k : arr){
        //     cout << k << '\n';
        // }
        
        if(is_include()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    
    return 0;
}