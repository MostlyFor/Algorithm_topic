#include <string>
#include <vector>

using namespace std;

vector<int> answer = {0,0};

// 만약 해당 영역이 모두 같은 수라면 그 값 리턴하고
// 아니면 4개로 나누어서 함수 부르는 함수.
// nxn
void f(vector<vector<int>>& arr,int x, int y, int n){
    // 만약 모든 영역이 같은 수가 아니면 1/4쪼개서 함수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[x+i][y+j] != arr[x][y]){
                f(arr, x, y, n/2);
                f(arr, x+n/2, y, n/2);
                f(arr, x, y+n/2, n/2);
                f(arr, x+n/2, y+n/2, n/2);
                return;
            }
        }
    }

    //만약 모든 영역이 같은 수라면
    arr[x][y] == 0 ? answer[0]++ : answer[1]++;

}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();

    f(arr,0,0,n);

    return answer;
}