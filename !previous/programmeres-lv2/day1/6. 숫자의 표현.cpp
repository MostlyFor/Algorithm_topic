#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int s = 1;
    int e = 1;
    int window = 1;
    
    
    while(s!=n){
        if(window<n){
            e++;
            window += e;
        }
        else if(window>n){
            window -=s;
            s++;
        }
        else{
            answer ++;
            e++;
            window+=e;
        }
    }
    return answer+1;
}