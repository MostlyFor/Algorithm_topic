n = int(input())

arr = []


res = 1
i = 1
while res <= 4294967295: # 문제에서 주어진 최대값
    res = (i *(i+1))//2
    if res == n:
        print(i)
        break
    elif res > n:
        print(i-1)
        break
    i+=1
    arr.append(res)

    