#include <string>
#include <vector>
using namespace std;

vector<int> arr[9]; // arr[k] : N을 k 번써서 만들 수 있는 수 집합

int solution(int N, int number) {
    // 괄호 = 이미 한 연산에 대해 수행해야함 즉, 4개를 써서 만들 수 있는 애 = 0 + 4, 1 + 3, 2 + 2로 봐야 하기에 각각 연산 결과 저장해야함
    
    arr[1] = {N};
    arr[2]=  {11 * N, 2 * N, 0, N * N, 1};
    arr[3] = {111 * N};
    arr[4] = {1111 * N};
    arr[5] = {11111 * N};
    arr[6] = {111111 * N};
    arr[7] = {1111111 * N};
    arr[8] = {11111111 * N};
    
    for(int i=0; i<8; i++){
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j] == number) return i;
        }
    }
    
    for(int i=3; i<=8; i++){
        int res = 0;
        for(int j=1; j<= i/2; j++){
            // arr[j] 와 arr[i-j]의 곱
            for(auto x : arr[j]){
                for(auto y : arr[i-j]){
                    arr[i].push_back(x + y); if(arr[i].back() == number) return i;
                    arr[i].push_back(x - y); if(arr[i].back() == number) return i;
                    arr[i].push_back(x * y); if(arr[i].back() == number) return i;
                    if(y) arr[i].push_back(x / y); if(arr[i].back() == number) return i;
                    if(x) arr[i].push_back(y / x); if(arr[i].back() == number) return i;
                }
            }
        }
    }
    
    
    
    return -1;
}