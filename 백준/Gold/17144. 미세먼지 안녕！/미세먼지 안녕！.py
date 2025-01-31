import sys
from collections import deque
input = sys.stdin.readline
dx = [0,1,-1,0]
dy = [1,0,0,-1]



n, m, T = map(int,input().rstrip().split())
board = [list(map(int,input().split())) for _ in range(n)]
turn = 0



def spread():
    board_tmp = [row[:] for row in board]
    
    for i in range(n):
        for j in range(m):
            if board_tmp[i][j] >= 5:
                mass = board_tmp[i][j] // 5

                check = 0
                for dir in range(4):
                    nx = i + dx[dir]
                    ny = j + dy[dir]
                    
                    if 0<= nx < n and 0<= ny < m and board_tmp[nx][ny] != -1:
                        board[nx][ny] += mass
                        check+=1
                
                board[i][j] -= mass * check

def run():
    board_tmp = [row[:] for row in board]
    first = 0
    second = 0
    
    # 공기 청정기 시작 위치
    for i in range(n):
        if board[i][0] == -1:
            if first: second = i
            else: first = i
        
    # first로부터 반시계방향 이동
    for i in range(0, first):
        board[i+1][0] = board_tmp[i][0]

    board[first][0] = -1

    for j in range(0, m-1):
        board[first][j+1] = board_tmp[first][j]
    
    board[first][1] = 0

    for i in range(first, 0, -1):
        board[i-1][m-1] = board_tmp[i][m-1]
    
    for j in range(m-1, 0, -1):
        board[0][j-1] = board_tmp[0][j]
    

    # second로부터 시계방향 이동
    for j in range(0, m-1):
        board[second][j+1] = board_tmp[second][j]
    board[second][1] = 0

    for i in range(second, n-1):
        board[i+1][m-1] = board_tmp[i][m-1]
    
    for j in range(m-1, 0, -1):
        board[n-1][j-1] = board_tmp[n-1][j]
    
    for i in range(n-1, second-1, -1):
        board[i-1][0] = board_tmp[i][0]
    board[second][0] = -1
    

    

while turn < T:
    turn +=1
    # 1. 미세먼지 확산
    spread()
    # for zz in board:
    #     print(*zz)

    # 2. 공기청정기 작동
    run()

print(sum(sum(row) for row in board) + 2)
    

            
