#include <string>
#include <vector>
#include <map>
using namespace std;

bool all_zero(vector<int> number){
    for(auto i : number)
        if(i!= 0) return false;
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string,int> m;
    
    for(int i=0; i<want.size(); i++)
        m[want[i]] = i;
    
    
    for(int i=0 ;i<10; i++) 
        if(m.find(discount[i])!= m.end())
            number[m[discount[i]]]--;
    
    if(all_zero(number)) answer++;
    
    int st = 0;
    for(int i=10; i<discount.size();i++){
        if(m.find(discount[st]) != m.end())
            number[m[discount[st++]]]++;
        else st++;
        if(m.find(discount[i])!= m.end())
            number[m[discount[i]]]--;
        
        if(all_zero(number)) answer++;
    }
    
    while(st!=discount.size()){
        if(m.find(discount[st]) != m.end()) 
            number[m[discount[st++]]]++;
        else st++;
        if(all_zero(number)) answer++;
    }
    
    
    
    return answer;
}