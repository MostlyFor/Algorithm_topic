#include <string>
#include <iostream>
#include <vector>
using namespace std;

int length[500001];
int pos[500001];

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();

    for(int i=0; i<n; i++){
        int x = a[i];
        int& x_length = length[x];
        int& x_pos = pos[x];
        
        // 전에 것과 묶는 경우
        if (i-1 >=0 && (x_pos <=i-1) && (a[i] != a[i-1])) {
            x_pos = i+1;
            x_length+=2;
            answer = max(answer, x_length);
        }
        
        // 뒤에 것과 묶는 경우
        if(i+1 < n && (x_pos <=i) && (a[i] != a[i+1])) {
            x_pos = i+2;
            x_length+=2;
            answer = max(answer, x_length);
        }
    }
    
    return answer;
}