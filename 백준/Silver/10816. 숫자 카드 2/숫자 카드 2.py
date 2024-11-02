n = int(input())
arr = list(map(int, input().split()))
hmap = {}

for i in arr : hmap[i] = hmap.get(i,0) + 1

m = int(input())

for x in input().split():
    print(hmap.get(int(x), 0), end = ' ')