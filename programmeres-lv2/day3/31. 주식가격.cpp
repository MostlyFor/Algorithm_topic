#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    
    //현재 최솟값 그때의 인덱스
    stack<pair<int,int>> st;
   
    
    for(int i=prices.size()-1; i>=0; i--){
        // 임의의 값이 있고 스택엔 값이 차있다고 하자.
        // 답을 결정지을 수 있는 순간은 나보다 작은 값을 찾았을 때이다.
        
        // 스택에서 나보다 더 작은 값 찾기
        while(!st.empty() && st.top().first >= prices[i]){
            st.pop();
        }
        //없으면 얘가 최솟값이 된다.
        if(st.empty()) {
            answer.push_back(prices.size()-1 - i);
            st.push({prices[i],i});
        }
        // 있으면 얘 답 결정지을 수 있다. 그리고 얘도 스택에 넣어야 한다. 다음에 얘보다 큰 값 나올수도 있다.
        else {
            
            answer.push_back(st.top().second - i);
            st.push({prices[i],i});
            
        }
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}