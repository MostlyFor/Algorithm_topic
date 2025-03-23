#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 재귀적으로 트리를 파싱하여 canonical form(정규화된 표현)을 만드는 함수
// tokens: 전위 순회 결과를 저장한 토큰 벡터
// index: 현재 파싱 위치 (참조로 전달)
string parseTree(vector<string>& tokens, int &index) {
    // '#'이면 현재 노드가 없음(자식 목록 종료) → 빈 문자열 반환
    if (index >= tokens.size() || tokens[index] == "#") {
        index++;  // '#' 토큰 건너뛰기
        return "";
    }
    
    // tokens[index]는 현재 노드의 레이블 (이름은 무시하므로 사용하지 않음)
    index++;  // 노드 레이블 소비
    
    // 현재 노드의 자식 canonical string들을 저장할 벡터
    vector<string> children;
    // '#' 토큰이 나오기 전까지 자식 노드를 재귀적으로 파싱
    while (index < tokens.size() && tokens[index] != "#") {
        children.push_back(parseTree(tokens, index));
    }
    index++;  // 자식 리스트 종료를 나타내는 '#' 건너뛰기

    // 자식 canonical string들을 정렬하면, 자식들의 순서가 달라도 동일한 표현을 얻을 수 있음
    sort(children.begin(), children.end());
    
    // 현재 노드의 canonical 표현: "(" + (정렬된 자식 표현 결합) + ")"
    string rep = "(";
    for (auto &child : children)
        rep += child;
    rep += ")";
    return rep;
}

// 입력 문자열(트리의 전위 순회 결과)을 canonical form으로 변환하는 함수
string getCanonical(const string &treeStr) {
    vector<string> tokens;
    istringstream iss(treeStr);
    string token;
    while (iss >> token)
        tokens.push_back(token);
    
    int index = 0;
    return parseTree(tokens, index);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    cin.ignore(); // T 입력 후 남은 개행문자 제거
    
    while(T--){
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        
        string canon1 = getCanonical(tree1);
        string canon2 = getCanonical(tree2);
        
        if(canon1 == canon2)
            cout << "The two trees are isomorphic." << "\n";
        else
            cout << "The two trees are not isomorphic." << "\n";
    }
    
    return 0;
}