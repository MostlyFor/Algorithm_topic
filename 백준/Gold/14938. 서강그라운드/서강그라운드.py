import sys
from collections import deque
import heapq

n, m, r = map(int, input().split())
items = list(map(int, input().split()))

adj = [[] for _ in range(n+1)]

for _ in range(r):
    a,b,c = map(int, input().split())
    adj[a].append((b,c))
    adj[b].append((a,c))





def djikstra(st):

    dist = [1e9] * (n+1)

    heap = []
    heapq.heappush(heap, (0, st))
    dist[st] = 0

    while heap:
        cost, here = heapq.heappop(heap)
        cost = -1 * cost

        if dist[here] < cost: continue
        

        for ne in adj[here]:
            next = ne[0]
            next_cost = ne[1]


            if next_cost + cost < dist[next]:
                dist[next] = next_cost + cost
                heapq.heappush(heap, (-dist[next], next))

    return sum(items[i-1] for i in range(n+1) if dist[i] <= m)



ans = 0
for i in range(1, n+1):
    ans = max(ans, djikstra(i))

print(ans)
