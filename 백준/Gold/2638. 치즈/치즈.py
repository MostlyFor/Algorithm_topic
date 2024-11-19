import sys
from collections import deque


input = sys.stdin.readline

n, m = map(int,input().rstrip().split())

dx = [0,1,-1,0]
dy = [1,0,0,-1]

board = [list(map(int,input().split())) for _ in range(n)]

cnt = sum(sum(row) for row in board)


t = 0


def bfs(visit, st):
    queue = deque([])
    queue.append(st)

    while queue:
        x, y = queue.popleft()

        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]

            if not (0<= nx < n and 0<= ny < m): continue
            if board_tmp[nx][ny] + visit[nx][ny] >= 1: continue
            visit[nx][ny] = 1
            queue.append((nx,ny))



while cnt > 0:
    t+=1
    board_tmp = [row[:] for row in board]
    visit = [[0] * m for _ in range(n)]

    # 외부 공기 체크
    for i in range(n):
        for j in range(m):
            if i != 0 and j !=0 and i != n-1 and j != m-1: continue
            if visit[i][j]: continue
            bfs(visit, (i,j))



    for i in range(n):
        for j in range(m):
            if board_tmp[i][j]:
                check = 0
                for dir in range(4):
                    nx = i + dx[dir]
                    ny = j + dy[dir]
                
                    if 0<= nx < n and 0<= ny < m and board_tmp[nx][ny] == 0 and visit[nx][ny] == 1:
                        check += 1
                
                if check >= 2:
                    board[i][j] = 0
                    cnt-=1

print(t)