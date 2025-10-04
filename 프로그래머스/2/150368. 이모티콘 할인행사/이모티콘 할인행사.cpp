#include <string>
#include <vector>

using namespace std;

int discount[4] = {10,20,30,40};

pair<int,int> answer;
int n, m;

void f(int idx, vector<int>& discounts, vector<vector<int>>& users, vector<int>& emoticons){
    if(idx == m){
        
        int person = 0;
        int accounts = 0;
        
        // n 명의 유저들에 대해
        for(int i=0; i<n; i++){
            int account = 0;
            
            // 아이템 할인율
            for(int j=0; j<m; j++){
                int p = discount[discounts[j]];
                
                // 할인율보다 크다.
                if(p >= users[i][0]){
                    account += emoticons[j] / 100 * (100 - p);
                }
                
            }
            
            if(users[i][1] <= account) person++;
            
            else accounts += account;
        }
        
        if(answer < make_pair(person, accounts)){
            answer = make_pair(person, accounts);
        }
        return;
    }
    
    
    for(int p=0; p<4; p++){
        discounts.push_back(p);
        f(idx+1, discounts, users, emoticons);
        discounts.pop_back();
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    // (서비스 가입자 수, 이모티콘 판매액)
    
    // users [비율, 가격], n <= 100
    // emoticons [이모티콘 정가], m <= 7
    
    // 할인은 10% 20% 30% 40%
    // 최대 경우의 구 4 ^ 7 => 2 ^ 14 => 16000
    // 각 경우마다 users 구매여부 []
    
    n = users.size();
    m = emoticons.size();
    vector<int> tmp;
    
    f(0, tmp, users, emoticons);
    
    vector<int> ans = {answer.first, answer.second};
    return ans;
}