#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown /2 + 2;
    
    int y = 3;
    int x = sum -y;
    
    
    while(x>=y){
        if(x*y == brown + yellow) return {x,y};
        x--; y++;
    }
    
    return answer;
}