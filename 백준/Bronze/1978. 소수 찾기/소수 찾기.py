n = int(input())

arr = list(map(int, input().split()))

is_prime = [1] * 1001
is_prime[1] = 0

for i in range(2,int(1000**0.5)+1):
    if is_prime[i]:
        for j in range(i*i, 1001, i):
            is_prime[j] = 0

ans = sum(1 for x in arr if is_prime[x])
print(ans)