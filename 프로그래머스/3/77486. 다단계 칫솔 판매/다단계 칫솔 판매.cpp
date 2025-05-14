#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



unordered_map<string,int> id_map; // 이름 - 사원 번호
int parent[10001]; // 자신을 소개해준 사람 번호
int money[10001];


void dfs(int id, int amt){
    if(parent[id] == id) return;
    int fee = amt / 10;
    money[id] += amt - fee;
    
    if(fee == 0) return;
    dfs(parent[id], fee);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int id = 0;
    id_map.insert({"center", 0});
    for(auto s: enroll) id_map.insert({s, ++id});
    
    // 부모 저장
    for(int i=0; i<referral.size(); i++){
        auto a = id_map[enroll[i]];
        auto b = id_map[referral[i]];
        // a는 b의 소개로 가입
        parent[a] = b;
    }
    
    // 수익 나눔
    for(int i=0; i<seller.size(); i++){
        int id = id_map[seller[i]];
        int amt = amount[i] * 100;
        dfs(id, amt);
    }
    
    vector<int> ans;
    for(auto s : enroll){
        int id = id_map[s];
        ans.push_back(money[id]);
    }
    
    return ans;
}