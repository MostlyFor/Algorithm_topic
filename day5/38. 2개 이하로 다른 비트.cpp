#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    
    for(auto l : numbers){
        long long cnt = 1;
        int now = 0;
        int prev = 0;
        long long k = l;
        
        while(l>=0){
            now = l%2;
            if(now==0){
                k = k+cnt;
                if(prev ==1){
                    k = k-cnt/2;
                }
                answer.push_back(k);
                break;
            }
            prev = now;
            l /=2;
            cnt = cnt*2;
        }
        
        
    }
    
    
    
    return answer;
}