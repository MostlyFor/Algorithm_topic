s = input()


tmp = ""
ans = 0
idx = 100
for i in range(len(s)):
    if s[i] == '-':
        idx = i
        break

plus = s[:idx]
plus = plus.replace('-', '+')
minus = s[idx+1:]
minus = minus.replace('-', '+')

for i in plus.split('+'):
    ans += int(i)

if minus:
    for i in minus.split('+'):
        ans -= int(i)

print(ans)