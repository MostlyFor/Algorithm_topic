import sys
from collections import deque
input= sys.stdin.readline

n = int(input().rstrip())

dp = [1e9] * 50001
arr = []

for i in range(1,int(50000**0.5)+1):
    dp[i * i] = 1
    arr.append(i*i)

for i in range(n+1):
    for t in arr:
        if i >= t:
            dp[i] = min(dp[i], dp[i-t] + dp[t])

print(dp[n])