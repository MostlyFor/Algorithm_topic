#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

struct Node{
    int node_num;
    int x; 
    int y;
    Node* left = nullptr;
    Node* right = nullptr;
};
unordered_map <long long, int> hmap;
priority_queue<pair<int,int>> pq;

Node* root;
vector<int> route1, route2;

// k가 들어갈 위치 찾기
void find(int x, int y, int idx, Node* par){
    // 부모보다 x값이 작으면 왼쪽
    if(x < par->x){
        if(par->left == nullptr) {
            Node* tmp = new Node{idx, x, y};
            par->left = tmp;
        }
        else find(x, y, idx, par-> left);
    }
    
    // 부모보다 값이 크면 오른쪽
    else if(par->x < x){
        if(par->right == nullptr) {
            Node* tmp = new Node{idx, x, y};
            par->right = tmp;
        }
        else find(x, y, idx, par->right);
    }
}

void get_route1(Node* p){
    route1.push_back(p->node_num);
    if(p->left) get_route1(p->left);
    if(p->right) get_route1(p->right);
}

void get_route2(Node* p){
    if(p->left) get_route2(p->left);
    if(p->right) get_route2(p->right);
    route2.push_back(p->node_num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // 1번부터 들어있는 좌표를 트리 형태로 구성 
    
    // 0. 노드 번호 구성
    for(int i=0; i<nodeinfo.size(); i++){
        auto node = nodeinfo[i];
        hmap.insert({node[0] * 10000 + node[1], i+1});
    }
    
    // 1. 같은 레벨에 있는 노드는 같은 y 좌표를 가진다 -> y 좌표를 기반으로 정렬 -> 레벨 구함 (nlogn)
    for(auto node : nodeinfo) pq.push(make_pair(node[1], node[0]));
    
    auto k = pq.top(); pq.pop();
    Node* tmp = new Node();
    tmp->y = k.first;
    tmp->x = k.second;
    tmp->node_num = hmap[tmp->x * 10000 + tmp->y];
    root = tmp;
    
    // 2. find를 이용해서 원하는 위치 찾아주기 (nlogn) -> 트리의 깊이가 1000 이하인 경우만 나옴!
    while(pq.size()){
        k = pq.top(); pq.pop();
        int y = k.first;
        int x = k.second;
        int node_num = hmap[x * 10000 + y];
        find(x, y, node_num, root);
    }
    
    // 전위 순회 O(N)
    get_route1(root);
    
    // 후위 순회 O(N)
    get_route2(root);

    vector<vector<int>> answer = {route1, route2};
    return answer;
}