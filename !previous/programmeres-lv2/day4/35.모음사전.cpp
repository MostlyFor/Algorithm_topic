#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 많이 비효율적인 풀이

 char apha[] = {'A','E','I','O','U'};

void make(int n, vector<string>& dic, string k){
    if(k.size() == n){
        dic.push_back(k); return;
    }
    for(int i=0; i<5; i++)
        make(n,dic,k+apha[i]);
}


int solution(string word) {
    int answer = 0;
   
    vector<string> dic;
    
    string k ="";
    for(int i=1; i<=5; i++)
        make(i,dic,k);
    
    sort(dic.begin(),dic.end());
    
    auto w = find(dic.begin(),dic.end(),word);
    
    
    return w-dic.begin()+1;
}