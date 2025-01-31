#include <iostream>
using namespace std;

class Node{
    public:
    bool is_end;
    Node *children[26];

    Node(){
        for(int i=0; i<26; i++) children[i] = nullptr;
        is_end = false;
    }
};

Node *root = new Node();

void insert(string s){
    
    Node *p = root;

    for(int i=0; i<s.size(); i++){
        int idx = s[i] - 'A';

        if(p->children[idx] == nullptr) p->children[idx] = new Node();

        p = p->children[idx];
    }

    p->is_end = true;
}

// p로 시작하는 애 다 출력
void f(Node *p, string base, int idx){
    char alpha= 'A' + idx;
    cout << base << alpha << '\n';

    for(int i=0; i<26; i++){
        if(p->children[i]) f(p->children[i], base+"--", i);
    }
}

int main() {
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int len; cin >> len;
        string tmp;
        char t;
        while(len--) {
            cin >> t;
            tmp += t;
        }

        insert(tmp);
    }

    for(int i=0; i<26; i++){
        if(root->children[i]) f(root->children[i], "", i);
    }
    return 0;
}