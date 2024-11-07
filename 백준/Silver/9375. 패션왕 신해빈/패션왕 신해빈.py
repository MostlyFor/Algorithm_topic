import sys
input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    
    n = int(input())

    hmap = {}
    
    for _ in range(n):
        a, type = input().rstrip().split()
        hmap[type] = hmap.get(type, 0) + 1

    arr = list(hmap.values())
    ans = 1
    for i in arr: ans *= i+1

    print(ans -1)