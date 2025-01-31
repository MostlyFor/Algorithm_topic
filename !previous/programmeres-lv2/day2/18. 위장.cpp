#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> closet;
    
    
    for(auto i : clothes){
        closet[i[1]] +=1;
    }
    
    auto iter = closet.begin();
    
    
    while(iter != closet.end()){
        answer *= (iter++->second +1);
    }
    
    
    
    return answer-1;
}