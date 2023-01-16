#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    
    for(long long p = left; p<=right; p++){

    int x = p / n; int y = p % n;
    x >= y ? answer.push_back(x+1) : answer.push_back(y+1);
    }

    
    return answer;
}
