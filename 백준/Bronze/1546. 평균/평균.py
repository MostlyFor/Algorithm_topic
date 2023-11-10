n = int(input())
arr = list(map(int, input().split()))
best = max(arr)

new_arr = map(lambda x : x / best * 100, arr)

print(sum(new_arr) / n)
