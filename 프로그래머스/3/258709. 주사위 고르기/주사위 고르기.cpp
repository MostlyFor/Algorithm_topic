#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> a_dices;
vector<vector<int>> b_dices;
vector<int> a_dice;
vector<vector<int>> dice;
int n;

void split(int idx){
    if(a_dice.size() == n/2){
        a_dices.push_back(a_dice);
        
        vector<bool> is_in_a(n, 0);
        for(auto x : a_dice) is_in_a[x] = 1;
        
        vector<int> b_dice;
        
        for(int i=0; i<n; i++){
            if(!is_in_a[i]) b_dice.push_back(i);
        }
        
        b_dices.push_back(b_dice);
        return;
    }
    
    for(int i=idx; i<n; i++){
        a_dice.push_back(i);
        split(i+1);
        a_dice.pop_back();
    }
}

void get_scores(int step, vector<int>& arr, vector<int>& a_scores, vector<int>& b_scores, vector<int>& dice_a, vector<int>& dice_b){
    if(step == n/2){
        int a = 0;
        int b = 0;
        for(int i=0; i<n/2; i++){
            a += dice[dice_a[i]][arr[i]];
            b += dice[dice_b[i]][arr[i]];
        }
        a_scores.push_back(a);
        b_scores.push_back(b);
        return;
    }
    
    for(int i=0; i<6; i++){
        arr.push_back(i);
        get_scores(step+1, arr, a_scores, b_scores, dice_a, dice_b);
        arr.pop_back();
    }
}


vector<int> simulation(vector<int>& dice_a, vector<int>& dice_b){
    vector<int> arr = {0,0,0}; // 승, 무, 패
    
    vector<int> a_scores; // a 주사위가 얻을 수 있는 조합의 수
    vector<int> b_scores; // b 주사위가 얻을 수 있는 조합의 수
    
    vector<int> tmp;
    get_scores(0, tmp, a_scores, b_scores, dice_a, dice_b);
    
    sort(a_scores.begin(), a_scores.end());
    sort(b_scores.begin(), b_scores.end());
    
    int total_num = a_scores.size();
    
    for(int i=0; i<total_num; i++){
        int a_score = a_scores[i];
        // a가 이후로는 항상 짐
        int upper_idx = upper_bound(b_scores.begin(), b_scores.end(), a_score) - b_scores.begin();
        // a가 이거 이전엔 항상 이김
        int lower_idx = lower_bound(b_scores.begin(), b_scores.end(), a_score) - b_scores.begin();
        
        arr[0] += lower_idx;
        arr[1] += upper_idx - lower_idx;
        arr[2] += total_num - upper_idx;
    }
    
    return arr;
}

// A가 1,2,3 가져가서 비교하나 B가 1,2,3 가져가서 비교하나 똑같음 -> 이거 반영해야함
vector<int> solution(vector<vector<int>> d) {
    dice = d;
    n = dice.size();
    split(0); // A와 B 주사위 나눔
    
    vector<int> max_score = {0,0,0};
    vector<int> answer;
    
    for(int i=0; i<a_dices.size(); i++){
        vector<int> arr = simulation(a_dices[i], b_dices[i]); // 승, 무, 패
        if(max_score < arr){
            max_score = arr;
            answer = a_dices[i];
        }
    }
    for(auto& x : answer) x++;
    return answer;
}