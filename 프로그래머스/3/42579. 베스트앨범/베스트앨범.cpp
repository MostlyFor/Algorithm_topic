#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map <string,int> hmap;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 장르 별 가장 많이 재생된 두 개
    // 가장 많이 재생된 장르
    // 재생 횟수가 같다면 고유 번호 낮은 노래 순서
    
    // 10000개가 끝
    
    
    int n = plays.size();
    
    // 1. 장르 별 재생 순서 => hashmap에 통합으로 하고 숫자 맵핑 (가장 많이 나온 장르 1) 
    for(int i=0; i<n; i++){
        hmap[genres[i]] += plays[i];
    }
    
    // 장르 별 재생 횟수 정렬
    vector<pair<int, string>> tmp;
    for(auto it : hmap) tmp.push_back({it.second, it.first});
    sort(tmp.begin(), tmp.end());
    
    int idx = 0;
    for(int i=tmp.size()-1; i>=0; i--){
        hmap[tmp[i].second] = idx++;
    }
    
    // 2. <장르 번호, -재생횟수, 고유 번호> 튜플 생성
    vector <tuple<int,int,int>> arr;
    for(int i=0; i<n; i++){
        arr.push_back(make_tuple(hmap[genres[i]], -plays[i], i));
    }
    sort(arr.begin(), arr.end());
    
    // 3. 장르 별로 2개만 출력
    vector<int> is_done(hmap.size(), 0);
    
    vector<int> answer;
    for(int i=0; i<n; i++){
        if(is_done[get<0>(arr[i])] == 2) continue;
        answer.push_back(get<2>(arr[i]));
        is_done[get<0>(arr[i])]++;
    }
    
    return answer;
}