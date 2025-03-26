#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <string, int> hmap; // {보석 종류, 인덱스}

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 100001};
    
    // 모든 보석을 포함하는 가장 짧은 구간 찾기
    
    int idx = 0;
    for(auto gem : gems){
        if(hmap.find(gem) != hmap.end()) continue;
        hmap[gem] = idx++;
    }
    
    vector<int> window(idx, 0);
    int type_cnt = 0; // 현재 윈도우에 들어있는 타입 개수
    
    int l = 0;
    int r = 0;
    
    // 보석이 다 찬 경우 l 범위 줄이기
    // 줄이다가 모든 보석이 없으면 r 다시 진행
    
    while(r < gems.size()){
        // 보석이 다 찰 때까지 오른쪽으로 진행
        while(r < gems.size() && type_cnt != idx){
            if(window[hmap[gems[r]]] == 0) type_cnt++; // 만약 없는 보석이었으면 추가
            window[hmap[gems[r]]]++;
            r++;
        }
        
        // l 앞으로 가기
        while(type_cnt == idx){
            
            if(answer[1] - answer[0] > r - l){
                answer[1] = r;
                answer[0] = l;
            }
            
            window[hmap[gems[l]]]--;
            if(window[hmap[gems[l]]] == 0) type_cnt--; // 해당 보석이 더 이상 없으면 제거
            l++;
        }
    }
    
    answer[0]++;
    return answer;
}