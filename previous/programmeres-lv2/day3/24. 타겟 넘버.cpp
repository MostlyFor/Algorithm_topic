#include <string>
#include <vector>

using namespace std;
int answer = 0;

void f(vector<int>& numbers, int target,int index){
    if(index >= numbers.size()){
        if(target ==0) answer ++;
        return;
    }
        f(numbers,target-numbers[index],index+1);
        f(numbers,target+numbers[index],index+1);
    
    return;
}


int solution(vector<int> numbers, int target) {
    
    //총 2^n승 개 필요한데..
    f(numbers, target,0);
    
    return answer;
}