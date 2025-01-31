#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    
    vector<int> b;
   
    
    int a = n;
    while(a!=0){
        b.push_back(a%2);
        a/=2;
    }
    
    
    
    
    reverse(b.begin(),b.end());
    
   
    
    next_permutation(b.begin(),b.end());
    
    
    
    int k = 1;
    int answer = 0;
    for(int i=0; i<b.size(); i++){
        answer += b[b.size()-1-i] *k;
        k*=2;
    }
    
    //여기서 생각 잘못함
    //10000  인 경우 11100 -> 10011 11100
    if(answer<n){
        prev_permutation(b.begin(),b.end());
        b.push_back(0);
        int one = 0;
        int zero = 0;
        for(int i=0; i<b.size(); i++){
            if(b[i]==1) one++;
            else zero ++;
        }
        
        vector<int> z;
        while(--one)
            z.push_back(1);
        while(zero--)
            z.push_back(0);
        
        z.push_back(1);
        
        int x =1;
        answer = 0;
        for(int i=0; i<z.size();i++){
            answer+= z[i]*x;
            x*=2;
        }
        
        return answer;
    }
    
    //11111인 경우
    if(n==answer){
        return answer + answer/2 +1;
    }
    
    return answer;
    
    
}