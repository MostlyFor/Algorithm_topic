#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int> sl;
    set<int> sr;
    vector<int> l(topping.size(), 0);
    vector<int> r(topping.size(), 0);
    int lt = 0, rt =0;
    
    for(int i=0; i<topping.size(); i++){
        if(sl.find(topping[i]) == sl.end()){
            ++lt;
            sl.insert(topping[i]);
        }
        l[i] = lt;
        
        if(sr.find(topping[topping.size()-i-1])== sr.end()){
            rt ++;
            sr.insert(topping[topping.size()-i-1]);
        }
        
        r[topping.size()-i-1] =rt;
    }
    
    
    for(int i=0; i<topping.size()-1; i++){
        if(l[i] == r[i+1]) {
            answer ++;
        }
    }

    
    
    return answer;
}