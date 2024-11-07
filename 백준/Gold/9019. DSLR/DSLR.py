import sys
from collections import deque
input = sys.stdin.readline

T = int(input().rstrip())
dir = ['D', 'S', 'L', 'R']



for _ in range(T):
    a, b = map(int, input().rstrip().split())

    dist = [0] * 10000
    route = [""] * 10000
    q = deque()
    q.append(a)
    dist[a] = 1

    while q:
        h = q.popleft()
        n = -1
        for i in dir:
            if i == 'D': 
                n = h*2 % 10000

            if i == 'S':
                n = h-1
                if n == -1: n = 9999

            if i == 'L':
                tmp = str(10000 + h)
                tmp = tmp[1:]
                n = int(tmp[1] + tmp[2] + tmp[3] + tmp[0])

            if i == 'R':
                tmp = str(10000 + h)
                tmp = tmp[1:]
                n = int(tmp[3] + tmp[0] + tmp[1] + tmp[2])

            if dist[n] != 0: continue
            dist[n] = dist[h] + 1
            route[n] += route[h] + i
            q.append(n)
            if n == b: q.clear()
    
    print(route[b])
