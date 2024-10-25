n = int(input())

arr = []
for i in range(n):
    age, name =input().split()
    arr.append([int(age), i, name])

arr = sorted(arr)

for age, num, name in arr:
    print(age, name)
