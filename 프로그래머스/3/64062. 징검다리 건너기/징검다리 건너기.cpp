#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    // 항상 가장 가까운 디딤돌로 뛰기 가능 하지만 최대로 뛸 수 있는건 k까지
    // 이때, 최대 몇 명까지 징검다리 건널 수 있는지?
    
    // 만약 가장 쉽게 풀면 O(20만 * 2억)
    // 일단 첫 단계에서 최소 -> 해당만큼 뛸 수 있음, 계속 최소를 볼까? 
    // 이제 해당 최소에 0 생김
    
    // => 내 앞에 k개가 0이 되면 게임 끝 => i+1 ~ i+k 가 0이 되도록 하는 최솟값
    // O(N * K <= 10만^2)
    
    // i+1 ~ i+k의 최댓값의 최솟값을 봐야함
    // 슬라이딩 윈도우 쓰면 어떨까? // 30분
    
    int n = stones.size();
    
    int l = 0;
    priority_queue<pair<int, int>> window; // {돌 크기, 인덱스}, window 구간 [l : l+k-1]
    
    while(window.size() < k-1) window.push({stones[l+window.size()], l+window.size()});
    
    int answer = 1e9; // [l ~ r]의 최댓값의 최솟값
    
    // O(nlogk)
    while(l+k-1 < n){
        window.push({stones[l+k-1], l+k-1});
        // 최댓값을 꺼내서 윈도우 안에 속하는지 확인
        auto tmp = window.top();
        int number = tmp.first;
        int index = tmp.second;
        // cout << "구간 확인" << l << ' ' << l+k-1 << '\n';
        
        if(index < l || l + k < index) {
            window.pop();
            // cout << l << ' ' << answer << '\n';
        }
        else{
            answer = min(answer, number);
            // cout << l << ' ' << answer << '\n';
            l++;
        }
    }
    
    return answer;
}