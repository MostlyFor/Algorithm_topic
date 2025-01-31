#include <string>
#include <vector>
#include <iostream>

using namespace std;

int f(int a,int b){
    if(a > b) swap (a,b);
    
    while(a != 0){
        b = b % a;
        swap(a,b);
    }
    
    return b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int m1 =  arrayA[0];
    int m2 = arrayB[0];
    
    for(int i=0; i<arrayA.size()-1; i++){
        m1 = f(m1,arrayA[i+1]);
        m2 = f(m2,arrayB[i+1]);
    }
    
    for(int i =0; i<arrayB.size(); i++){
        if(arrayB[i] % m1  == 0) m1 = 1;
        if(arrayA[i] % m2 == 0) m2 = 1;
    }
    if(m1==1 && m2 == 1) return 0;
    
    return m1>m2 ? m1 : m2;
}