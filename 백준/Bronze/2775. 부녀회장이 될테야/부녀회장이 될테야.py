T = int(input())


floor = [[0] * 15 for _ in range(15)]

for j in range(1, 15):
    floor[0][j] = j

for j in range(1, 15): # 1호 ~ 14호
    for i in range(1, 15): # 0층 ~ k층
        floor[i][j] = sum(floor[i-1][x] for x in range(j+1)) 




for _ in range(T):
    k = int(input())
    n = int(input())
    print(floor[k][n])
    