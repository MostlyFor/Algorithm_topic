#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(tuple<long long, long long, int>& a, tuple<long long, long long,int>& b){
    if(get<0>(a) * get<1>(b) >  get<0>(b) * get<1>(a)) return true;
    else if(get<0>(a) * get<1>(b) < get<0>(b) * get<1>(a)) return false;
    
    if(get<2>(a) < get<2>(b)) return true;
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stage_count(N+2, 0); // 해당 스테이지에 머물고 있는 사람 - 분자
    vector<int> stage_count_acc(N+2, 1); // 해당 스테이지를 포함해 이상 스테이지에 머물고 있는 사람 - 분모
    
    for(auto st : stages) stage_count[st]++;
    stage_count_acc[N+1] = stage_count[N+1];
    
    // 누적합 갱신
    for(int i=N; i>=0; i--){
        stage_count_acc[i] = stage_count[i] + stage_count_acc[i+1];
    }
    
    vector<tuple<long long, long long, int>> failure_rank;
    for(int i=1; i<=N; i++) failure_rank.push_back(make_tuple(stage_count[i], stage_count_acc[i], i));
    
    sort(failure_rank.begin(), failure_rank.end(), cmp);
    
    for(auto k : failure_rank) answer.push_back(get<2>(k));
    return answer;
}