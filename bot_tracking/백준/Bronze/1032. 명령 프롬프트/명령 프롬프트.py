n = int(input())

arr = []
for _ in range(n):
    arr.append(input())

ans = list(arr[0])

for j in arr:
    for i in range(len(ans)):
        if ans[i] != j[i]:
            ans[i] = '?'

print("".join(ans))
