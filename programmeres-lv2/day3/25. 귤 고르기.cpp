#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // 종류, 개수 -> 개수별로 정렬해야하는데...
    map<int,int> m;
    
    for(auto i : tangerine){
        m[i]++;
    }
    
    
    // 앙 여기서 겹칠수도 있겠구나 vector<int>로 바꿔야겠네
    vector<pair<int,int>> v;
    
    for(auto it = m.begin(); it!=m.end(); it++)
        v.push_back({it->second,it->first});
    
    sort(v.begin(),v.end());
    
    
    auto iter = v.end();
    iter --;
    
    while(k>0){
        k -= iter->first;
        iter --;
        answer ++;
    }
    
    
    
    return answer;
}