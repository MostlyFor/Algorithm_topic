#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long k : numbers){
        
        if(k%2 == 0) {
            answer.push_back(k+1); continue;
        }
        
        //비트 11, -> 110
        long long a = 3;
        
        //비트 01, -> 
        long long co = 1;
        while(( k & a) != co){
            a = a<<1;
            co = co << 1;
        }
        answer.push_back(k + a -2*co);
        
    }
    return answer;
}