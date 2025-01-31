#include <string>
#include <vector>
#include <algorithm>
using namespace std;

 char apha[] = {'A','E','I','O','U'};

void make(vector<string>& dic, string k){
    if(k.size()==6) return;
    
    dic.push_back(k);
    
    for(int i=0; i<5; i++)
        make(dic,k+apha[i]);
}


int solution(string word) {
    int answer = 0;
   
    vector<string> dic;
    
    string k ="";
    
    make(dic,k);

    
    auto w = find(dic.begin(),dic.end(),word);
    
    
    return w-dic.begin();
}