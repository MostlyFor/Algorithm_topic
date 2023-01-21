#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    
    // 1 2 4 ->3으로 나눈 나머지
    // 11 12 14 21 22 24 41 42 44 -> 9로 나눈 나머지 중 3개
    // 111 112 114 121
    // 1 = 3 x 0 + 1
    // 2 = 3 x 0 + 2
    // 3 = 3 x 1 + 0
    
    int cnt = 3;
    
    while(n>0){
        int k = cnt/3;
        int a = (n-1)%cnt;
        if(a<k) answer = '1' + answer;
        else if(2*k<=a) answer ='4' + answer;
        else answer = '2' + answer;
        
        n -= cnt;
        cnt*=3;
    }
    
    
    return answer;
}