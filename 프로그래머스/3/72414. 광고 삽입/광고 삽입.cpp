#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> event_time;
int score[1000000];
long long arr[1000000]; // 점수 누적합

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int ho = stoi(adv_time.substr(0, 2));
    int mi = stoi(adv_time.substr(3, 2));
    int se = stoi(adv_time.substr(6, 2));
    
    int dist = 3600 * ho + 60 * mi + se; // 구간 길이
    
    ho = stoi(play_time.substr(0, 2));
    mi = stoi(play_time.substr(3, 2));
    se = stoi(play_time.substr(6, 2));
    
    int total = 3600 * ho + 60 * mi + se;
    
    
    // O(N) : 사람이 언제 접속하고 있는지 이벤트 기록
    for(int i=0; i<logs.size(); i++){
        auto log = logs[i];
        int h = stoi(log.substr(0, 2));
        int m = stoi(log.substr(3, 2));
        int s = stoi(log.substr(6, 2));
        
        int h2 = stoi(log.substr(9, 2));
        int m2 = stoi(log.substr(12, 2));
        int s2 = stoi(log.substr(15, 2));

        score[h * 3600 + m * 60 + s]++;
        score[h2 * 3600 + m2 * 60 + s2]--; 
        // score가 의미하는 것 = 해당 지점부터 사람이 score개수만큼 있음
    }
    
    // O(N) : 점수 기록 및 누적
    arr[0] = score[0];
    for(int i=1; i<=total; i++){
        score[i] = score[i-1] + score[i];
        arr[i] = arr[i-1] + score[i]; // arr[i] : score[i]까지의 누적합
    }
    
    // 시간 돌면서 누적 점수 기록
    int i = 0;
    long long total_score = 0;
    int best_time = 0;
    
    while(i + dist <= total){
        // 갱신
        if(total_score < arr[i+dist-1] - arr[i] + score[i]){
            total_score = arr[i+dist-1] - arr[i] + score[i];
            best_time = i;
        }
        i++;
    }
    
    int hc = best_time / 3600;
    best_time -= hc * 3600;
    int mc = best_time / 60;
    int sc = best_time % 60;
    
    if(hc < 10) answer += "0";
    answer += to_string(hc) + ":";
    
    if(mc < 10) answer += "0";
    answer += to_string(mc) + ':';
    
    if(sc < 10) answer += "0";
    answer += to_string(sc);
    
    cout << total_score << ' ';
    
    return answer;
}