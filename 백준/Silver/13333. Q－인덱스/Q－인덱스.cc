#include <iostream>
using namespace std;

int arr[1000];

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    int q_index = n;
    while(q_index){
        int k = 0;
        for(auto i : arr){
            if(q_index <= i) k++;
        }
        
        if(q_index <= k) break;
        q_index--;
    }
    
    
    cout << q_index;
    
    return 0;
}