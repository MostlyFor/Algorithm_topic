n, m = map(int, input().split())
cmd = list(map(int, input().split()))

arr = [i for i in range(1, n+1)]


# 1 2 3 4 5
# 1 2 3 3 2

ans = 0

for x in cmd:
    # min(왼쪽으로 꺼내는 경우, 오른쪽으로 꺼내는 경우)
    st = 0
    ed = len(arr)-1
    idx_x = arr.index(x)
    ans += min(idx_x, ed - idx_x + 1)
    while arr[0] != x:
        tmp = arr.pop(0)
        arr.append(tmp)
    arr.pop(0)

print(ans)