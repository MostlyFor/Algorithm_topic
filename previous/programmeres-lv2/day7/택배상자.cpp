#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    int i = 0;
    
    stack<int> st;
    // 3가지 옵션
    // 1. stack에서 뽑아서 맞는지 본다. 2. 벨트에서 나오는지 본다. 3. 스택에 저장한다.
    // -> 벨트에서 나오는걸 스택에 저장하고 stack을 본다
    
    for(int belt=1; belt<=order.size(); belt++){
        st.push(belt);
        
        while(!st.empty() && st.top() == order[i]){
            answer++; i++; st.pop();
        }
    }
    
    return answer;
}