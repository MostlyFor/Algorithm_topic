n = int(input())

line = 0
while line < n:
    print(' ' * line + '*' * (2 * (n-line) -1))
    line+=1

line -= 1
while line > 0:
    line -=1
    print(' ' * line + '*' * (2 * (n-line) -1))