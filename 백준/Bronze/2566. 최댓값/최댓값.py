arr = [list(map(int, input().split())) for _ in range(9)]

ans = -1
x = -1
y = -1
for i in range(9):
    for j in range(9):
        if ans < arr[i][j]:
            x = i; y = j; ans = arr[i][j]

print(ans)
print(x+1, y+1)
