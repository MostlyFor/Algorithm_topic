#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    // 총 N명 A와 B가 언제 대전하는지?
    
    // 1로 빼고 2로 나눈 나머지가 같다면 서로 붙는거겠네
    // (1 2) (3 4) (5 6) (7 8)
    // 1 2 3 4
    // 일단 k 라운드 후에 a가 몇번을 받는지 계산
    
    while((a-1)/2 != (b-1)/2){
        answer++;
        a=(a+1)/2;
        b=(b+1)/2;
    }
    

    return answer;
}