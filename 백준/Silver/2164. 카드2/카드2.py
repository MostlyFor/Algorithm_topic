n = int(input())

arr = []

for i in range(n):
    arr.append(i+1)

idx = 0

for _ in range(n-1):
    idx+=1
    tmp = arr[idx]
    arr.append(tmp)
    idx+=1

print(arr[-1])


