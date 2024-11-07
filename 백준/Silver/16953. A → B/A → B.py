n, m = map(int, input().split())

ans = -1
    
def f(x, cnt):
    global ans
    if ans != -1: return

    if x < n: return

    if x == n:
        ans = cnt
        return
    
    if x % 2 == 0:
        f(x//2, cnt+1)

    elif x % 10 ==1:
        f(x//10, cnt+1)

f(m, 1)

print(ans)