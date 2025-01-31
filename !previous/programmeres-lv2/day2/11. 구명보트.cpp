#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    
    // 가장 적은 사람이 가능한 가장 큰 사람을 데려가고 남은 사람들 k명 끼리 a개의 쌍을 만들었다고 치자. 그러면 총 a+1쌍이다.
    // 그러면 [가장 적은 사람 + k명] -> 가장 적은 사람이 k명 중 매칭이 안된 사람을 데려가면 a+1쌍이 된다. 즉 이 경우 최대 a+1쌍이므로 몸무게 가장 적은 사람은 항상 자기가 데리고 갈 수 있는 가장 큰 사람을 데려가야 한다.
    
    sort(people.begin(),people.end());
    
    int left = 0, right =people.size()-1;
    
    // 1명만 남은 경우
    if(left == right) return 1;
    
    
    while(left<right){
        //현재 무거운 사람 태울 수 없다면 더 가벼운 사람으로 대체
        if(people[left]+people[right] > limit) {
            right --; continue;
        }
        // 태울 수 있다면 둘이 타고 감
        left ++; right --; answer++;
    }
    
   
    
    //50 50 70 80
    
    return people.size() - answer;
}