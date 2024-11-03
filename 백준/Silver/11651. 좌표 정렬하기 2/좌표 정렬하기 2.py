n = int(input())


arr = []

for _ in range(n):
    a, b = map(int, input().split())
    arr.append((b,a))

arr.sort()

for y,x in arr:
    print(x,y,sep=' ')