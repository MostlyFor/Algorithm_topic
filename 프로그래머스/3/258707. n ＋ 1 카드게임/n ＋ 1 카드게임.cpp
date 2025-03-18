#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
unordered_map <int, int> hmap; // 해당 수가 등장하는 인덱스
priority_queue<int> pq; // 장바구니
int turn;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    int idx =0; // 다음에 뽑을 카드 수
    int pass = 1; // 만들어진 조합 수
    
    for(int i=0; i<n; i++){
        hmap[cards[i]] = i;
    }
    
    
    // 초기 조건
    for(idx=0; idx<n/3; idx++){
        if(hmap[n+1 - cards[idx]] < idx){
            hmap[cards[idx]] = 1e9;
            hmap[n+1 - cards[idx]] = 1e9;
            pass++;
        }
    }
    
    // idx ~ idx + 2 * pass 에서의 최솟값을 coin이 떨어질때까지 사기
    while(pass){
        if(idx == n){
            turn++;
            break;
        }
        while(pass){
            pass--;
            turn++;
            pq.push(-hmap[n+1 - cards[idx++]]);
            pq.push(-hmap[n+1 - cards[idx++]]);
        }

        // 가장 우선순위로 사야 하는 애
        if(coin <= 0 || idx <= -pq.top()) break;
        else{
            // 하나로 충당 가능한 경우
            int match_idx = -pq.top(); pq.pop();
            coin--;
            if(hmap[cards[match_idx]] < n/3){
                hmap[cards[match_idx]] = 1e9;
                hmap[n+1 - cards[match_idx]] = 1e9;
                pass++;
            }
            else{
                if(coin <= 0) break;
                int match_idx2 = -pq.top(); pq.pop();
                coin--;
                hmap[cards[match_idx]] = 1e9;
                hmap[cards[match_idx2]] = 1e9;
                pass++;
            }
        }
    }
    
    return turn;
}