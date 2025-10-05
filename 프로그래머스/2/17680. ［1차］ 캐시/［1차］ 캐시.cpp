#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> 

using namespace std;
unordered_map<string, int> cache; // 도시이름, 최근에 쓰인 시간

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    int t = 0;
    for(auto city : cities){
        t++;
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        // cout << city << ' ';
        if(cache.find(city) == cache.end()){
            answer += 5;
            cache[city] = t;
        }
        else {
            answer += 1;
            cache[city] = t;
        }
        
        // 가장 오래된 페이지 교체
        if(cache.size() > cacheSize){
            string remove_candidate = "";
            int oldest = 1e9;
            for(auto c : cache){
                string k = c.first;
                int time = c.second;
                
                if(time < oldest){
                    remove_candidate = k;
                    oldest = time;
                }
            }
            
            cache.erase(remove_candidate);
            // cout << city << ' ' << remove_candidate << ' ';
        }
    }    
    return answer;
}