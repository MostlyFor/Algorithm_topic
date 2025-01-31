import sys
from collections import deque
input= sys.stdin.readline

n, m= map(int,input().rstrip().split())

tel = {}

for _ in range(n+m):
    a, b= map(int,input().rstrip().split())
    tel[a] = b

visit = [0] * 101
queue = deque()

queue.append(1)
visit[1] = 1

while queue:
    h = queue.popleft()

    for i in range(1, 6+1):
        n = h + i
        if n <= 0 or n > 100: continue
        if visit[n]: continue

        if tel.get(n, 0):
            jump_n = tel.get(n,0)
            if visit[jump_n]: continue
            visit[jump_n] = visit[h]+1
            queue.append(jump_n)
            
        else:
            visit[n] = visit[h]+1
            queue.append(n)

print(visit[100]-1)


