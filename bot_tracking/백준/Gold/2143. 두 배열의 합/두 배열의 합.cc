#include <iostream>
#include <unordered_map>
using namespace std;

int arr1[1000];
int arr2[1000];

unordered_map<int,int> hmap;


int main(){
    int T; cin >> T;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    
    hmap.reserve(n*n);
    
    int m; cin >> m;
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr1[j];
            hmap[sum]++;
        }
    }
    
    long long answer = 0;
    for(int i=0; i<m; i++){
        int sum = 0;
        for(int j=i; j<m; j++){
            sum += arr2[j];
            answer += hmap[T-sum];
        }
    }
    
    cout << answer;
    
    return 0;
}