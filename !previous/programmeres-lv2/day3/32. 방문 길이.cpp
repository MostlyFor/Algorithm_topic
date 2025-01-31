#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<pair<int,int>> s;

    pair<int,int> now = {0,0};

    for(auto ch : dirs){
        if(ch =='L') {
            if(now.first == -5) continue;
            int a = (now.first+5) * 100 + now.second+5;
            now.first--;
            int b = (now.first+5) * 100 + now.second+5;
            s.insert({a,b});
            s.insert({b,a});
        }
        if(ch =='U') {
            if(now.second == 5) continue;
            int a = (now.first+5) * 100 + now.second+5;
            now.second++;
            int b = (now.first+5) * 100 + now.second+5;
            s.insert({a,b});
            s.insert({b,a});
        }
        if(ch =='D') {
            if(now.second == -5) continue;
            int a = (now.first+5) * 100 + now.second+5;
            now.second--;
            int b = (now.first+5) * 100 + now.second+5;
            s.insert({a,b});
            s.insert({b,a});
        }
        if(ch =='R') {
            if(now.first == 5) continue;
            int a = (now.first+5) * 100 + now.second+5;
            now.first++;
            int b = (now.first+5) * 100 + now.second+5;
            s.insert({a,b});
            s.insert({b,a});
        }
    }

    return s.size()/2;
}
