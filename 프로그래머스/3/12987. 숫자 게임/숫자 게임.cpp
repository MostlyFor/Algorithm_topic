#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    // B 팀이 가장 크게 이길 수 있는 경우의 수
    // A, B의 길이는 10만까지
    // 각 원소는 10억 이하
    
    
    // 이건 그냥 그리디하게 현재 A를 이길 수 있는 최솟값 주면 될 것 같은데,
    // 근데 현재 A를 이기는게 항상 최선인가에 대해 고민해봐야함
    // 만약 현재 A를 이기지 않고 해당 카드를 아껴서 다른 곳에 쓴다면? 
    // -> 오름차순 정렬하고 그리디 전략 하면 될듯
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0;
    int j = 0;
    
    int answer = 0;
    for(int i=0; i<A.size(); i++){
            
        // B에서 이길 수 있을 때 까지 카드 꺼냄
        while(j < B.size() && A[i] >= B[j]){
            j++;
        }
        
        if(j <B.size()) {
            answer++; j++; // 발견했다면 사용
        }
    
    }
    
    return answer;
}