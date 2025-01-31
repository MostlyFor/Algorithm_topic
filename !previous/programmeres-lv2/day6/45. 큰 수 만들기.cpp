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
        
        if(k!=0 && number.size()-left >=k+1){
            int M  = 0;
            int right = left;
            
            //크기 k+1짜리 윈도우 - 여기서 인덱스 초과날수도 있음
            while(right-left+1<=k+1){
                M = max(M,number[right++]-'0');
            }
            
            //left가 최댓값 될때까지 지우기
            while(number[left] - '0' !=M){
                left++; k--;
            }
        }
        
        answer+=number[left];
        left ++;
    }
    
    while(k--)
        answer.pop_back();
    
    
    return answer;
}