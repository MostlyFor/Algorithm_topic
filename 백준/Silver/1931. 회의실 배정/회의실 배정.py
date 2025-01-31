import sys
input = sys.stdin.readline

n = int(input().rstrip())

arr = []

for _ in range(n):
    a,b = map(int, input().rstrip().split())
    arr.append((a,b))

arr.sort(key = lambda x : (x[1], x[0]))

ans = 0
end_t = 0

for x, y in arr:
    if x >= end_t:
        end_t = y
        ans +=1

print(ans)
