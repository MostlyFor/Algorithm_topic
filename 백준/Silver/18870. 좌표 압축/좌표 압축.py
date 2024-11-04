import sys
input = sys.stdin.readline

n = int(input().rstrip())

arr = list(map(int, input().rstrip().split()))

arr_sorted = sorted(set(arr))

hmap = {} # 나보다 작은 원소의 개수 저장

hmap[arr_sorted[0]] = 0 # 초기값

for i in range(1, len(arr_sorted)):
    hmap[arr_sorted[i]] = i

for x in arr:
    print(hmap[x], end=' ')

