#include <iostream>
using namespace std;

int n;

int abcd[26][2];
    // 전위 - 부모 -> 왼쪽 -> 오른쪽
    // 중위 - 왼쪽 -> 부모 -> 오른쪽
    // 후위 - 왼쪽 -> 오른쪽 -> 부모

void f1(int root){
    char h = 'A' + root;
    cout << h;
    if(abcd[root][0]) f1(abcd[root][0]);
    if(abcd[root][1]) f1(abcd[root][1]); 
}

void f2(int root){
    if(abcd[root][0]) f2(abcd[root][0]);
    char h = 'A' + root;
    cout << h;
    if(abcd[root][1]) f2(abcd[root][1]); 
}

void f3(int root){
    if(abcd[root][0]) f3(abcd[root][0]);
    if(abcd[root][1]) f3(abcd[root][1]);
    char h = 'A' + root;
    cout << h;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        char a, b, c; cin >> a >> b >> c;
        if(b!='.') abcd[a-'A'][0] = b-'A';
        if(c!='.') abcd[a-'A'][1] = c-'A';
    }
    
    f1(0); cout << '\n';
    f2(0); cout << '\n';
    f3(0); cout << '\n';
    
    return 0;
}