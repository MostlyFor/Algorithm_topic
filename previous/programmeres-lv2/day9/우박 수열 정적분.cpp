#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> graph = {k};
    
    while(k!=1){
        if(k%2 == 0) k /=2;
        else if(k%2 ==1) k = k*3+1;
        
        graph.push_back(k);
    }
    
    vector<double> rec;
    rec.push_back(0);
    for(int i=1; i<graph.size(); i++){
        rec.push_back((graph[i] + graph[i-1])*1.0 /2);
    }
    
        
    for(auto a : rec)
        cout << a << ' ';
    
    for(int i=1; i<rec.size(); i++){
        rec[i] = rec[i] + rec[i-1];
    }
    
    
    
    //rec[0]  = 0 rec[1] 0~1 까지의 넓이 rec[2] 0~2까지의 넓이
    
    for(auto range :ranges){
        
        int st = range[0];
        int end = range[1];
        
        
        end = rec.size()+end -1;
        
        if(st > end) answer.push_back(-1);
        else answer.push_back(rec[end]- rec[st]);
    }
    
    
    return answer;
}