#include <string>
#include <vector>

using namespace std;


int gcd(int a,int b){
    if(a*b == 0) return a+b;
    
    
    return a>=b ? gcd(a%b, b) : gcd(b%a,a);
}


int solution(vector<int> arr) {
    
    if(arr.size()==1) return arr[0];
    
    for(int i=1; i<arr.size(); i++){
        
        arr[i] = arr[i] * arr[i-1] /gcd(arr[i-1], arr[i]);
    }
    
    return arr.back();
}