#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int give[50][50];
unordered_map<string, int> hmap;
int point[50];
int next_gifts[50];


int solution(vector<string> friends, vector<string> gifts) {
    // 친구들 끼리 관계 살펴보기
    
    int n = friends.size();
    
    for(int i=0; i<n; i++){
        hmap[friends[i]] = i;
    }
    
    // 선물 관계 2차원 맵핑
    for(auto g : gifts){
        string a_s = g.substr(0, g.find(' '));
        string b_s = g.substr(g.find(' ')+1);
        
        int a = hmap[a_s];
        int b = hmap[b_s];
        
        give[a][b]++;
    }
    
    // 선물 지수 산출
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) point[i] += give[i][j];
        for(int j=0; j<n; j++) point[i] -= give[j][i];        
    }
    
    // i 와 j의 선물 관계
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            // 1. 다른 경우 - 선물 더 많이 받은 사람이 줌
            if(give[i][j] > give[j][i]) next_gifts[i]++;
            else if(give[i][j] < give[j][i]) next_gifts[j]++;
            // 2. 같은 경우
            else{
                if(point[i] > point[j]) next_gifts[i]++;
                else if(point[i] < point[j]) next_gifts[j]++;
            }
        }
    }
    int answer = 0;
    
    for(auto g : next_gifts) answer = max(answer, g);
    return answer;
}