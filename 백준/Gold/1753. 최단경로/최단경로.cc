#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    int start;
    cin >> start;

    // map[i]의 원소들 <출발, 가중치>
    vector<pair<int, int>> map[v + 1];

    for (int i = 0; i < e; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        map[s].push_back({ e,w });
    }

    vector<int> dist(v + 1, -1);
    dist[start] = 0;

    //start부터 해서 갈 수 있는 곳으로 출발

    vector<int> visit(v + 1, 0);
    //목표 노드, 목표 노드까지의 걸린 거리
    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });
    while (!pq.empty()) {
        auto k = pq.top(); pq.pop();
        //현재 도착 노드 -> 여기서 최소임이 확정
        int here = k.second;
        int cost = -k.first;

        if (visit[here] == 1) continue;
        visit[here] = 1;
        dist[here] = cost;

        //이제 방문할 수 있는 인접 노드들 방문
        for (auto i : map[here]) {
            int target = i.first;
            int weight = i.second;


            if (visit[target] == 1) continue;
            //나를 거치고 가는 비용 넣기
            pq.push({ -dist[here] - weight , target });
        }

    }

    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] == -1) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}