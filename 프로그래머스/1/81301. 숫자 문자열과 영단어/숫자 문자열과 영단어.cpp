#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> dict;

int solution(string s) {
    // 문자열에서 영단어에 해당하는 부분 숫자로 바꾸기
    // tmp에 있는 것들 쌓일 때마다 변환 가능한지 확인
    
    dict["zero"] = "0";
    dict["one"] = "1";
    dict["two"] = "2";
    dict["three"] = "3";
    dict["four"] = "4";
    dict["five"] = "5";
    dict["six"] = "6";
    dict["seven"] = "7";
    dict["eight"] = "8";
    dict["nine"] = "9";
    dict["0"] = "0";
    dict["1"] = "1";
    dict["2"] = "2";
    dict["3"] = "3";
    dict["4"] = "4";
    dict["5"] = "5";
    dict["6"] = "6";
    dict["7"] = "7";
    dict["8"] = "8";
    dict["9"] = "9";
    
    string answer = "";
    string tmp = "";
    for(auto ch : s){
        tmp += ch;
        if(dict.find(tmp) != dict.end()){
            answer+= dict[tmp];
            tmp = "";
        }
    }
    
    return stoi(answer);
}