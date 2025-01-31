#include <string>
#include <vector>

using namespace std;

void f(int a, int b, int c, int n,vector<vector<int>>& answer){
    if(n==1){
        answer.push_back({a,c});
        return;
    }

    f(a,c,b,n-1,answer);
    answer.push_back({a,c});
    f(b,a,c,n-1,answer);
    return;
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    // 가장 최근 방법에서 2랑 3의 위치를 바꿈 + [1,3] + 가장 최근 방법에서 2와 1을 바꿈
    f(1,2,3,n,answer);
    return answer;
}