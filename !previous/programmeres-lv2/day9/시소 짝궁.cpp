#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<float,int> m;
    
    sort(weights.begin(), weights.end());
    
    for(int i=0; i<weights.size(); i++){
        m[weights[i]]++;
    }
    
    for(auto k : weights){
        answer += --m[k];
        answer += m[2*k];
        answer+= m[k*1.0/2 * 3];
        answer +=m[k*1.0/3 * 4];
    }
    
    
    return answer;
}