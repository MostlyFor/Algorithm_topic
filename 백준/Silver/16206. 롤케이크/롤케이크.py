n, m = map(int, input().split())
cakes = list(map(int, input().split()))


# n 개의 케이크 최대 m 번 잘라서 만들 수 있는 10의 개수
ten = 0 # 길이가 10인 케이크

# 20의 경우만 1번 잘랐을 때 2개가 나옴 -> 20을 우선적으로, 그 다음은 20을 만들 수 있는 30
cakes.sort(key = lambda x: (x % 10, x))

for cake in cakes:
    # 최선의 전략으로 자를 수 있는 경우
    if cake % 10 == 0 and m >= (cake // 10 - 1):
        m -= (cake // 10 - 1)
        ten += (cake // 10 - 1)+1
    
    # 전략없이 자르면 되는 경우
    else:
        while cake > 10 and m:
            ten +=1
            m-=1
            cake -= 10

print(ten)