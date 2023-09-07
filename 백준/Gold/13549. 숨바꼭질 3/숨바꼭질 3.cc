#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <queue>
#include <set>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

class Solution {

public:

    int init(int node, int s, int e, vector<int>& nums, vector<int>& tree) {
        if (s == e)
            return tree[node] = nums[s];

        int mid = (s + e) / 2;

        tree[node * 2] = init(node * 2, s, mid, nums, tree);
        tree[node * 2 + 1] = init(node * 2 + 1, mid + 1, e, nums, tree);

        return tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int max_el(int l, int r, int node, int s, int e, vector<int>& tree) {
        if (s > r || e < l) return -1e9;

        if (l <= s && r >= e) {
            return tree[node];
        }

        int mid = (s + e) / 2;

        return max(max_el(l, r, node * 2, s, mid, tree), max_el(l, r, node * 2 + 1, mid + 1, e, tree));
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums2(1, 0);
        for (int i = 0; i < nums.size(); i++)
            nums2.push_back(nums[i]);
        vector<int> tree(n * 4, 0);
        init(1, 1, n, nums2, tree); // nlogn 소요

        vector<int> answer;

        for (int i = 0; k + i <= n; i++) {
            answer.push_back(max_el(1 + i, k + i, 1, 1, n, tree));
        }

        return answer;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    if (n == k) {
        cout << 0; return 0;
    }

    // 학습에 쓸 pq 구현 (목적지까지의 비용, 목적지)
    priority_queue<pair<int, int>> pq;

    int dist[100001];

    // 거리 비용 초기화
    for (int i = 0; i < 100001; i++)
        dist[i] = 1e9;

    pq.push({ 0,n });
    dist[n] = 0;

    while (pq.size()) {
        auto h = pq.top(); pq.pop();
        int cost = -h.first;
        int node = h.second;

        if (node == k) {
            cout << dist[node];
            return 0;
        }

        // 내가 새로 갱신하려고 하던 경로의 값이 더 크면 무시
        if (dist[node] < cost) continue;

        //+1, -1 비용 1짜리 경로들
        for (int i = 0; i < 2; i++) {
            int next = node - 1;
            if (i == 1) next = node + 1;

            if (node < 0 || node >= 100001) continue;

            if (cost + 1 > dist[next]) continue;
            dist[next] = cost + 1;
            pq.push({ -dist[next],next });
        }

        // 2배로 가는 경로들 
        while (node * 2 < 100001) {
            if (dist[node * 2] <= dist[node]) break;
            dist[node * 2] = dist[node];
            pq.push({ -dist[node], node * 2 });
            node *= 2;
        }
    }

    return 0;
}