#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Q;
int n, m;
int start; // 출발지

vector<pair<int,int>> adj[2000]; // adj[a] = {b, w} a도시와 b 도시는 가중치 w로 이루어짐
vector<pair<int,int>> product[30001]; // 상품명, 1번부터 시작
priority_queue<pair<int,int>> pq; // 출발지로부터의 거리, 도착 장소

int dist[2000]; // 출발지로부터 2000까지의 거리


void dikstra(){
    // 처음 거리 배열 초기화 
    for(int i=0; i<n; i++) dist[i] = 1e9;

    dist[start] = 0;
    pq.push({0, start});

    while(pq.size()){
        auto tmp = pq.top(); pq.pop();
        int h_dist= -tmp.first; // 현재까지 오기까지의 거리
        int h = tmp.second;

        if(h_dist > dist[h]) continue; // 다익스트라 탈출 로직

        for(auto n : adj[h]){
            int next = n.first; // 다음 목적지
            int cost = n.second; // 다음으로 갈 때까지의 비용

            if(dist[next] > dist[h] + cost){ // 현재까지의 next까지의 최단 거리 관측

                dist[next] = dist[h] + cost; // 비용 갱신
            
                pq.push({-dist[next], next});
            }
        }
    }
}

// 1. 코드트리 랜드 건설
void make_land(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    // 다익스트라 초기화 (여행 상품 미리 계산하기)
    dikstra();
}

// 2. 여행 상품 생성
void make_product(){
    // 항상 출발지는 같고 목적지가 다름.
    // 각각의 상품은 id가 있고, 얻는 수익이 있음
    // id, 수익, 도착지
    int a,b,c; cin >> a >> b >> c;
    product[a].push_back({b,c});

}


// 3. 여행 상품 제거
void delete_product(){
    int a; cin >> a;
    product[a].clear(); // 이 부분 확인 필요
}


// 4. 최적의 여행 상품 판매 - 다익스트라 알고리즘
void sell(){
    // 최적의 정의 : revenue - cost가 최대인 상품
    // 같은 값을 가지는 상품이 여러 개일 경우 id가 가장 작은 상품
    // 이때 cost는 현재 상품의 출발지로부터 dest까지의 최단거리
    // 도달 불가 or revenue - cost가 음수면 -1 출력
    // 판매 시 id 출력 후 관리 목록에서 제거

    // 최적의 상품 찾기
    int best_id = -1;
    int best_profit = -1e9;
    for(int i=1; i<30001; i++){
        if(product[i].size()==1){
            int profit = product[i][0].first - dist[product[i][0].second]; // 이익 산출 비용

            if(best_profit < profit) {
                best_profit = profit;
                best_id = i;
            }
        }
    }

    if(best_profit < 0) cout << -1 << '\n';
    else {
        cout << best_id << '\n';
        product[best_id].clear();
    }
    return;
}

// 5. 여행 상품의 출발지 변경
void change_start(){
    int a; cin >> a;
    start = a;
    dikstra();
}




int main() {

    int Q; cin >> Q;

    for(int i=0; i<Q; i++){
        int cmd; cin >> cmd;

        if(cmd == 100) make_land();
        else if(cmd == 200) make_product();
        else if(cmd == 300) delete_product();
        else if(cmd == 400) sell();
        else if(cmd == 500) change_start();
    }
    
    return 0;
}