#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    
     
    vector<int> v(end-begin+1,1);
    long long base = begin;
    
    for(long long i = 2; i*i <=end; i++){
        for(long long j=begin/i; j*i<=end; j++){
            if(begin>j*i) continue;
            if(v[j*i -base]!=1) continue;
            if(j > 10000000) continue;
            v[j*i -base] = j;
        }
    }
    
    if(begin == 1) v[0] = 0;
    
    return v;
}