#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {return a>b;}

int solution(vector<int> cards) {
    int answer = 0;
    
    
    vector<int> v;
    
    for(int i=0; i<cards.size(); i++){
        if(cards[i] == 0) continue;
        int cnt = 0;
        while(cards[i] != 0){
            cnt ++;
            
            int next = cards[i]-1;
            cards[i] = 0;
            i = next;
        }
        v.push_back(cnt);
    }
    
    if(v.size()==1) return 0;
    
    sort(v.begin(),v.end(),comp);
    return v[0] * v[1];
}