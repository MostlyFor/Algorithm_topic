n,x = map(int, input().split())
arr = map(int, input().split())
for tmp in arr:
    if tmp < x:
        print(tmp, end = ' ')
