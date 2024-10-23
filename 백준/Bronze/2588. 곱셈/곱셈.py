x = int(input())
y = input()

ans = 0
cnt = 0

for ch in reversed(y):
    ans += x * int(ch) * 10 ** cnt
    cnt+=1
    print(x * int(ch))

print(ans)

