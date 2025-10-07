#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool is_digit(char ch){
    return 0<= ch-'0' && ch-'0' <=9;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string, int, int, string>> arr; // HEAD, NUMBER, 인덱스, 파일명
    // HEAD > NUMBER(int - 0과 ) > TAIL(아무거나 나타날 수 있음) 우선순위
    // 같은 순서에서는 어떻게? -> 원래 입력에 주어진 순서 (idx 보존)
    
    for(int i=0; i<files.size(); i++){
        string head = "";
        string file = files[i];
        int head_end = -1;
        // head 추출
        for(int j=0; j<file.size(); j++){
            char ch = file[j];
            // 처음 숫자가 아니라면 HEAD
            if(!is_digit(ch)){
                head += tolower(ch);
            }
            else {
                head_end = j;
                break;
            }
        }
        
        // tail 추출
        string number = "";
        for(int j=head_end; j<file.size(); j++){
            if(number.size() > 5 || !is_digit(file[j])){
                break;
            }
            number += file[j];
        }
        
        arr.push_back(make_tuple(head, stoi(number), i, file));
    }
    
    
    sort(arr.begin(), arr.end());
    
    for(auto k : arr){
        answer.push_back(get<3>(k));
    }
    
    return answer;
}