#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(),dungeons.end());

    do{
        int cnt = 0;
        int k_copy = k;

        auto iter = dungeons.begin();

        while(iter != dungeons.end() && k_copy>0){
            vector<int> tmp = *iter;
            int a = tmp[0]; int b = tmp[1];
            if(k_copy>=a){
                k_copy-=b;
                cnt++;
            }
            iter ++;
        }
        answer = max(answer,cnt);
    }while(next_permutation(dungeons.begin(),dungeons.end()));

    return answer;
}