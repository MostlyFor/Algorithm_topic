while 1:
    arr = list(map(int, input().split()))
    
    arr = [x**2 for x in arr]
    k = max(arr)

    if k == 0:
        break

    # 피타고라스 정리
    if k * 2 == sum(arr):
        print("right")
    else:
        print("wrong")