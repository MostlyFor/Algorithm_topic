#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int idx = 0;
    vector<int> children; // 자식
    int parent = -1;
};

Node node[51]; 
int n;
int r;

// x의 하위 트리의 리프 노트 수를 반환하는 함수
int f(int x){
    if(node[x].children.size() == 0) return 1;
    int ans = 0;
    int cnt = 0;
    
    // 모든 자식 노드들에 대해 더함
    for(auto k : node[x].children){
        if(k == r) continue;
        ans += f(k);
        cnt++;
    }
    
    return ans + (cnt == 0);
}


int main(){
    cin >> n;

    // 노드 자식 추가
    for(int i=0; i<n; i++){
        int x; cin >> x;
        node[i].idx = i;
        node[i].parent = x;
        if(x == -1) continue;
        node[x].children.push_back(i);
    }
    
    // 제거되는 노드    
    cin >> r;
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        // 얘가 루트 노드면 실행
        if(node[i].parent == -1 && i != r) ans += f(i);
    }
    
    
    cout << ans << '\n';
    

    
    return 0;
}