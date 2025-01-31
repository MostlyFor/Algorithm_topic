#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    //행 개수만큼 반복
    for(int i=0; i<arr1.size(); i++){
        vector<int> tmp;
        //행벡터 x 열벡터 (열 개수 만큼)
        for(int j=0; j<arr2[0].size(); j++){
            int k = 0;
            // 행벡터 x 열벡터
            for(int a = 0 ; a<arr1[0].size(); a++){
                k+= arr1[i][a] * arr2[a][j];
            }
            tmp.push_back(k);
        }
        answer.push_back(tmp);
    }
    
    return answer;
}