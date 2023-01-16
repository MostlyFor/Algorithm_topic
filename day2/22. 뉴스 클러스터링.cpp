#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {

    vector<string> a;
    vector<string> b;
    vector<string> c;
    vector<string> d;
    
    
    str1[0] = tolower(str1[0]);
    for(int i=0; i<str1.size()-1; i++){
        str1[i+1] = tolower(str1[i+1]);
        if('a'<=str1[i] &&str1[i] <='z'&&'a'<=str1[i+1] &&str1[i+1] <='z'){
            string tmp = "";
            tmp += str1[i];
            tmp += str1[i+1];
            a.push_back(tmp);
        }
    }

   
    
    str2[0] = tolower(str2[0]);
    for(int i=0; i<str2.size()-1; i++){
        str2[i+1] = tolower(str2[i+1]);
        if('a'<=str2[i] &&str2[i] <='z'&&'a'<=str2[i+1] &&str2[i+1] <='z'){
            string tmp = "";
            tmp += str2[i];
            tmp += str2[i+1];
            b.push_back(tmp);
        }
    }
    
  
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    set_union(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(d));
    
    
    
    
    
    if(c.size()==0) return 65536;
    float answer = d.size()*1.0/c.size();
    
    
    // 소숫점 버리기 어떻게?
    return int(answer * 65536);
}