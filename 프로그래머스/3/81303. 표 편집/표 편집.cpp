#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct List{
    List* next = nullptr;
    List* prev = nullptr;
    int value = -1;
};

stack<List*> st;

string solution(int n, int k, vector<string> cmd) {
    
    // 헤드 노드 생성
    List tmp;
    tmp.value = 0;
    List* head = &tmp;
    List* head2 = head;
    
    for(int i=1; i<n; i++){
        // 노드 이어서 생성
        List* tmp = new List;
        head->next = tmp;
        tmp->value = i;
        tmp->prev = head;
        head = head->next;
    }
    
    head = head2;
    
    // 더미 노드 생성
    List tmp2;
    tmp2.value = -1;
    head->prev = &tmp2;
    tmp2.next = head;
    
    while(k--) head = head->next;

    
    // 명령어의 개수 cmd 20만, 
    for(auto str : cmd){
        // U X, D X - O(N)
        if(str[0] == 'U' || str[0] == 'D'){
            string tmp = "";
            for(int i=2; i<str.size(); i++) tmp = tmp + str[i];
            int cnt = stoi(tmp);
            // cout << cnt << ' ';
            
            if(str[0] == 'U') while(cnt--) head = head->prev;
            
            else while(cnt--) head = head->next;
            
        }
        
        // C - O(1)
        if(str[0] == 'C'){
            st.push(head);
            if(head->next == nullptr){
                head->prev->next = nullptr;
                head = head->prev;
            }
            
            else{
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
            }
        }
        // Z - O(1)
        if(str[0] == 'Z'){
            List* p = st.top(); st.pop();
            
            // 끝 원소였던 경우
            if(p->next == nullptr){
                p->prev->next = p; // p->prev는 항상 살아있음이 보장되며, 끝 원소였으면 지금도 끝 원소
            }
            
            // 끝 원소 아닌 경우
            else{
                p->prev->next = p;
                p->next->prev = p;
            }
         }
    }
    
    while(head->prev){
        head = head->prev;
    }
    head = head->next;
    
    vector<int> arr(n, 0);
    
    while(head){
        arr[head->value] = 1;
        head = head->next;
    }

    string answer = "";
    for(int i=0; i<n; i++){
        if(arr[i]) answer += 'O';
        else answer += 'X';
    }

    return answer;
}


    
    // 연결리스트로 구현하면 컨트롤 제트는 어떻게 함
    
    // 이동 O(N)
    
    // 삭제 O(1)
    
    // ctrl z O(1)
    // 가장 최근에 지운 건 그 앞뒤 문맥은 살아있음
    // 앞뒤 문맥 가지고 바로 접근해서 살리면 O(1)에도 가능할듯
    // 일반적인 원소는 지우면 다음을 가리킴 (이전 정보가 남아있음)
    // 1 -> 2 -> 3
    // 1 지우면 2 이전이라는 정보가 남음 (2의 주소를 가지고 있어야 함)
    // 2 지우면 3 이전이라는 정보가 남음 (3의 주소를 가지고 있어야 함)
    // 근데 2의 주소는 새로 만들어져서 갱신됨
    // 2를 지우지 말고 포인터만 없애주면 되겠다
    
    
    
    
    
    // 배열 구현
    
    // 이동 O(N) - 중간중간 삭제된 애들이 있어서 생각해줘야 함
    // forward backward 둘 다 오래 걸림 중간에 삭제를 다 시키면
    
    // 삭제 O(1)
    
    // ctrl z O(1)