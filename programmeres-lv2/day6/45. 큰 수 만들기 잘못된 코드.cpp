#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int left =0;
    int right = 0;
    
    
    while(left!=number.size()){
        int M  = 0;
        //크기 k+1짜리 윈도우
        while(right-left+1!=k+1){
            M = max(M,number[right++]-'0');
        }
        
        //left가 최댓값 될때까지 지우기
        while(number[left] - '0' !=M) {
            left++; k--;
        }
        
        answer+=number[left];
        left ++;
        right= left;
    }
    
    
    
    return answer;
}