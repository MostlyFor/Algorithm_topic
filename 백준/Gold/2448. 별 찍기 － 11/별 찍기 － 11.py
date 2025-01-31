n = int(input())

arr = [[' ']*(2*n-1) for i in range(n)]


def f(x, base_r, base_c):
    if x == 3:
        arr[base_r][base_c+2] = '*'
        arr[base_r+1][base_c+1] = '*';arr[base_r+1][base_c+3] = '*'
        for i in range(5): arr[base_r+2][base_c+i] = '*'
    else:
        f(x//2, base_r, base_c+x//2)
        f(x//2, base_r+x//2, base_c)
        f(x//2, base_r+x//2, base_c+x)


f(n, 0, 0)
for line in arr:
    print("".join(line))