#include <iostream>
#include <vector>
using namespace std;

int get_sta(int st, int ed, int w){
    if(ed < st) return 0;
    return (ed - st + 1) / (2*w+1) + (((ed-st + 1) % (2*w+1)) > 0);
}


int solution(int n, vector<int> stations, int w)
{
    // 최소 기지국 수 
    
    // 2억 n개의 아파트, 기지국이 있는 곳, w는 전파의 도달 거리 (양 옆으로 w 커버 가능)
    
    // 그리디하게 접근하면 풀릴 듯 = 빈 칸이 있으면 거기서 가장 멀리
    
    int idx = 0; 
    int answer = 0;
    for(auto x : stations){
        x--;
        answer += get_sta(idx,  x - w -1, w);
        idx = x + w + 1;
    }
    
    answer += get_sta(idx, n-1, w);

    return answer;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//