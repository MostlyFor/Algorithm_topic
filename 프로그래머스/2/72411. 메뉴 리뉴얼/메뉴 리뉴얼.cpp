#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map <string, int> hmap;
int arr[11]; // 최대 갯수

void f(string order, int idx, int cnt, vector<char>& recipe){
    if(recipe.size() == cnt){
        string key = "";
        for(auto ch : recipe) key += ch;
        hmap[key]++;
        arr[cnt] = max(arr[cnt], hmap[key]);
        return;
    }
    
    
    for(int i=idx; i<order.size(); i++){
        recipe.push_back(order[i]);
        f(order, i+1, cnt, recipe);
        recipe.pop_back();
    }
    
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    // 단품 요리 -> 코스 요리
    // 코스 길이는 나와있는대로
    
    // orders 크기가 20
    // 최대 주문으 10개
    // 26 * 25 * ... * 17 가 최대 조합 개수
    // 모든 경우의 수를 봐야 함
    // 10개 -> 있는 경우 없는 경우 
    // 카운트는 어디에? -> 횟수(int, string) map string ++ 
    
    for(int cnt : course){
        // 최대 횟수
        for(auto& order : orders) {
            vector<char> recipe;
            sort(order.begin(), order.end());
            f(order, 0, cnt, recipe);
        }
    }
    
//     for(auto k : arr) cout << k << '\n';
    
    for(auto [k, v] : hmap){
        // 이 경우에만 정답에 추가
        if(arr[k.size()] == v && v > 1){
            answer.push_back(k);
        }
    }
    
    
    sort(answer.begin(), answer.end());
    
    return answer;
}