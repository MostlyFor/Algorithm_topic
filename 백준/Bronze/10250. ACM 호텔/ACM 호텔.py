T = int(input())

while T:
    T-=1

    a,b,c = map(int, input().split())
    x = (c-1)//a + 1

    y = c % a
    if y == 0:
        y = a
    print(y*100+x)