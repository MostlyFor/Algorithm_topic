n = int(input())

arr = list(map(int, input().split()))

is_prime = [1] * 1001

is_prime[1] = 0

for i in range(2,1001):
    cnt = i
    while(i * cnt <= 1000):
        is_prime[i*cnt] = 0
        cnt+=1

ans = 0
for x in arr:
    if is_prime[x]:
        ans+=1

print(ans)
    