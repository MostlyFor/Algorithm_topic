from collections import deque

a, b = map(int, input().split())

dp = [0] * 100001
method = [0] * 100001


q = deque()
q.append(a)
dp[a] = 1
method[a] = 1


cnt = 1
ans = 0

while q:
    cnt2 = cnt
    cnt = 0

    for _ in range(cnt2):
        h = q.popleft()
        
        ne = (h + 1, h-1, h*2)

        for n in ne:
            if 0 > n or 100000 < n: continue
            if dp[n] == dp[h]+1:
                method[n] += method[h]
            if dp[n]: continue

            dp[n] = dp[h]+1
            method[n] += method[h]
            q.append(n)
            cnt+=1


print(dp[b]-1)
print(method[b])
