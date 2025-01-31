#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct comp {
  bool operator()(string a, string b) { return a+b < b+a;}
};


string solution(vector<int> numbers) {
    string answer = "";
    
    priority_queue<string,vector<string>,comp> k;
    
    for(auto i : numbers)
        k.push(to_string(i));
    
    
    
    while(!k.empty()){
        answer+=k.top();
        k.pop();
    }
    
    if(answer[0]=='0') return "0";
    return answer;
}