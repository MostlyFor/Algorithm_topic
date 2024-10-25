#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> nmap; // 우선순위 판별 역할
stack<char> st; // 연산자 저장 역역할



int main(){
    string str; cin >> str;
    
    string tmp ="";
    string ans = "";
    
    nmap['+'] = 1;
    nmap['-'] = 1;
    nmap['*'] = 2;
    nmap['/'] = 2;
    nmap['('] = 0;
    
    int cnt = 0; // st 안에 들어있는 괄호 개수 
    
    
    
    for(auto ch : str){
        // 1. 현재 연산자 우선순위가 낮,동일 할때까지 하나로 묶어줘야 하므로 저장
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(st.size() > 0 && nmap[st.top()] >= nmap[ch]){
                tmp+=st.top(); st.pop();
            }

            st.push(ch);
            ans += tmp;
            tmp = "";
        }
        
        else if(ch == '('){
            st.push(ch);
        }
        
        // 다음 괄호 나올 때 까지 모두 다 빼기
        else if(ch == ')'){
            while(st.top() != '('){
                tmp += st.top(); st.pop();
            }
            st.pop(); //여는 괄호 제거
            ans += tmp;
            tmp = "";
        }
        
        else{
            tmp+=ch;
        }
    }
    
    ans += tmp;
    while(st.size()){
        ans += st.top(); st.pop();
    }
    
    cout << ans; 
    
    return 0;
}