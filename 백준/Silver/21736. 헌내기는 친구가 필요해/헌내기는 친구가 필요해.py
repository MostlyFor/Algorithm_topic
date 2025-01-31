import sys
from collections import deque
input= sys.stdin.readline

n, m = map(int, input().rstrip().split())

board = [input().rstrip() for _ in range(n)]
visit = [[0] * m for _ in range(n)]

dx = [0,1,-1,0]
dy = [1,0,0,-1]

queue = deque()
ans = 0

for i in range(n):
    for j in range(m):
        if board[i][j] == 'I':
            queue.append((i,j))
            visit[i][j] = 1


while queue:
    h = queue.popleft()

    for dir in range(4):
        nx = h[0] + dx[dir]
        ny = h[1] + dy[dir]

        if nx < 0 or ny < 0 or nx >= n or ny >=m: continue
        if visit[nx][ny] == 1: continue
        if board[nx][ny] == 'X': continue
        
        if board[nx][ny] == 'P': ans+=1

        visit[nx][ny] = 1
        queue.append((nx,ny))

if ans==0: print('TT')
else: print(ans)