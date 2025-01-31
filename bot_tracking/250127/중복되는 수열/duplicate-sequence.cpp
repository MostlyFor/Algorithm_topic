#include<iostream>
#include <vector>
using namespace std;
int n;


class TreeNode{
    public:
        TreeNode *children[10];
        bool is_end;

    TreeNode(){
        is_end = false;

        for(int i=0; i<10; i++){
            children[i] = nullptr;
        }
    }
};

TreeNode *root = new TreeNode();

void InsertWord(string s){
    TreeNode *p = root;

    for(int i=0; i<s.size(); i++){
        int idx = s[i] - '0';

        // 만약 자식이 없는 경우
        if(p->children[idx] == nullptr){
            p->children[idx] = new TreeNode();
        }

        p = p->children[idx];
    }

    p->is_end = true;
}

// s가 접두사가 아니면 true, 아니면 false
bool is_not_first(string s){
    TreeNode *p = root;

    // 해당 단어 맨 끝 찾아가기
    for(int i=0; i<s.size(); i++){
        int idx = s[i] - '0';
        p = p->children[idx];
    }

    bool has_child = false;
    for(int i=0; i<10; i++){
        if(p->children[i]) has_child=true;
    }

    return !has_child;
}

int main(){
    
    cin >> n;
    vector<string> arr;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        // Trie 구성 O(10000 * 10)
        InsertWord(str);
        arr.push_back(str);
    }

    bool ans = true;

    for(int i=0; i<n; i++){
        ans &= is_not_first(arr[i]);
    }

    cout << ans ? 1 : 0;
    
    return 0;
}