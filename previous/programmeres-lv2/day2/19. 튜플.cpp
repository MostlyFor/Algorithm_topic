#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    //
    vector<string> v(501, "");
    
    int left = 2;
    int comma =0;
    for(int i=1; i<s.size()-1;i++){
        if(s[i] == ',') comma++;
        if(s[i]== '}'){
            string tmp = s.substr(left,i-left);
            v[comma]=tmp+',';
            left = i+3;
            i+=2;
            comma = 0;
        }
    }
    
    set<int> se;
    
    //vector에 다 넣어짐.
    
    
    for(int i=0; i<v.size();i++){
        if(v[i] == "") break;
        
        //원소마다 시작함
        int st = 0;
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j] == ','){
                //새로운 숫자 나오면
                int number = stoi(v[i].substr(st,j-st));
                if(se.find(number)==se.end()){
                    answer.push_back(number);
                    se.insert(number);
                }
                
                st = j+1;
            }
        }
        
        
    }
   
    return answer;
}