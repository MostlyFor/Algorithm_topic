n = int(input())

board = [list(map(int, input().split())) for _ in range(n)]

dp = [[[0] * n for _ in range(n)] for _ in range(3)]

dp[0][0][1] = 1 # 여기까지 옮기는데 가능한 경우의 수 # 0은 가로, 1은 세로, 2는 대각

def in_board(a, b):
    return 0 <= a < n and 0 <= b < n

for i in range(n):
    for j in range(n):
        for k in range(3):
            if dp[k][i][j]:
                x = i
                y = j
                if k == 0:
                    nx = x
                    ny = y+1
                    if in_board(nx, ny) and board[nx][ny] == 0:
                        dp[0][nx][ny] += dp[k][i][j]
                    nx = x+1
                    ny = y+1
                    if in_board(nx, ny) and in_board(nx-1,ny) and in_board(nx,ny-1) and board[nx][ny] + board[nx-1][ny] + board[nx][ny-1]== 0:
                        dp[2][nx][ny] += dp[k][i][j]
                if k == 1:
                    nx = x+1
                    ny = y
                    if in_board(nx, ny) and board[nx][ny] == 0:
                        dp[1][nx][ny] += dp[k][i][j]
                    nx = x+1
                    ny = y+1
                    if in_board(nx, ny) and in_board(nx-1,ny) and in_board(nx,ny-1) and board[nx][ny] + board[nx-1][ny] + board[nx][ny-1]== 0:
                        dp[2][nx][ny] += dp[k][i][j]
                if k == 2:
                    nx = x
                    ny = y+1
                    if in_board(nx, ny) and board[nx][ny] == 0:
                        dp[0][nx][ny] += dp[k][i][j]
                    nx = x+1
                    ny = y+1
                    if in_board(nx, ny) and in_board(nx-1,ny) and in_board(nx,ny-1) and board[nx][ny] + board[nx-1][ny] + board[nx][ny-1]== 0:
                        dp[2][nx][ny] += dp[k][i][j]
                    nx = x+1
                    ny = y
                    if in_board(nx, ny) and board[nx][ny] == 0:
                        dp[1][nx][ny] += dp[k][i][j]

print(sum(dp[i][n-1][n-1] for i in range(3)))
