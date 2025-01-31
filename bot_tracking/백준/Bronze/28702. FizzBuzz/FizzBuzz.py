a = input()
b = input()
c = input()
target = 0

if 'Fizz' not in a and 'Buzz' not in a:
    target = int(a) + 3

if 'Fizz' not in b and 'Buzz' not in b:
    target = int(b) + 2

if 'Fizz' not in c and 'Buzz' not in c:
    target = int(c) + 1

ans = ""

if target % 3 == 0: ans += 'Fizz'
if target % 5 == 0: ans += 'Buzz'

if ans:
    print(ans)
else:
    print(target)