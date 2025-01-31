#include <iostream>
#include <vector>
using namespace std;

int n;
void f(vector<int> arr, vector<int> visit){
    if(arr.size() == n){
        for(auto k : arr) cout << k << ' ';
        cout << '\n';
        return ;
    }

    for(int i=0; i<n; i++){
        if(visit[i]) continue;
        arr.push_back(i+1);
        visit[i] = 1;
        f(arr, visit);
        visit[i] = 0;
        arr.pop_back();
    }
}
int main() {
    cin >> n;
    vector<int> visit(n ,0);
    f(vector<int>(), visit);
    
    return 0;
}