import bisect
T = int(input())

# x칸까지 가는데 걸리는 시간 저장
dp = [0, 1]
end = 2 ** 31
cnt = 1
while dp[-1] <= 2 ** 31:
    dp.append(dp[-1] + cnt)
    if len(dp) % 2 == 1:
        cnt+=1

for _ in range(T):
    a,b = map(int,input().split())
    x = b-a
    
    # x칸 까지 가는데 걸리는 시간
    print(bisect.bisect_left(dp, x))