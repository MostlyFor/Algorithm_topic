#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> line; // 크루들 도착시간
int base; // 첫 번째 버스 도착시간
int last_bus_time; 
int full;
int n, t;

int translate(string s){
    string h = s.substr(0, 2);
    string m = s.substr(3);
    return stoi(h) * 60 + stoi(m);
}

bool pos(int x){
    // cout << x << ' ';
    // for(auto k : line) cout << k << ' ';
    
    int idx = 0; // 대기열 번호
    int capa = 0; // 버스 좌석 수 
    for(int i=0; i<n; i++){
        capa = 0;
        int bus_time = base + t * i;
        // 탈 수 있는 사람 타기
        while(idx < line.size() && line[idx] <= bus_time && capa < full){
            capa++;
            // 매번 사람이 탈 때마다 콘이 먼저 탈 수 있으면 탐
            if(x <= bus_time && x < line[idx]) return true;
            idx++;
        }
        if(x <= bus_time && capa < full) return true;
    }
    
    return false;
}

string solution(int N, int T, int m, vector<string> timetable) {
    int corn_time = 0; // 막차
    n = N;
    t = T;
    full = m;
    base = translate("09:00");
    last_bus_time = base + (n-1) * t;
    for(auto t : timetable) line.push_back(translate(t));
    sort(line.begin(), line.end());
    
    // 마지막 버스 도착시간부터 내려오면서 가능한지 판단
    while(last_bus_time){
        if(pos(last_bus_time)){
            corn_time = last_bus_time;
            break;
        }
        
        last_bus_time--;
    }

    string answer = "";
    string hh = to_string(corn_time / 60);
    string mm = to_string(corn_time % 60);
    if(hh.size() == 1) hh = "0" + hh;
    if(mm.size() == 1) mm = "0" + mm;
    answer = hh + ":" + mm;

    return answer;
}

    