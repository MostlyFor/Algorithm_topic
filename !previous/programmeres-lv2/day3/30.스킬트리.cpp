#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    
    int abcd[26] = {0};
    
    for(auto k : skill)
        abcd[k-'A']++;
    
    
    for(auto s : skill_trees){
        string tmp = "";
        for(auto x : s){
            if(abcd[x-'A']) tmp+=x;
        }
        if(skill.find(tmp)==0) answer++;
    }
    
    
    return answer;
}