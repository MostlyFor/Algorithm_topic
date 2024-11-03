a, b = map(int, input().split())

is_prime = [1] * 1000001
is_prime[1] = 0

for i in range(2, b+1):
    if is_prime[i] == 0: continue
    for j in range(i*i, b+1, i):
        is_prime[j] = 0

for i in range(a, b+1):
    if is_prime[i]:
        print(i)