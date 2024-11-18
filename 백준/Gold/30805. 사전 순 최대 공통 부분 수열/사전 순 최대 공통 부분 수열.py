n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

ans = []


def get_max_element(arr1, arr2):
    if len(arr1) == 0 or len(arr2) == 0:
        return 0
    

    tmp1 = max(arr1)
    tmp2 = max(arr2)

    if tmp1 > tmp2:
        arr1.remove(tmp1)
        return get_max_element(arr1, arr2)
    
    elif tmp1 < tmp2:
        arr2.remove(tmp2)
        return get_max_element(arr1, arr2)
    
    else:
        index1 = arr1.index(tmp1)
        index2 = arr2.index(tmp2)
        del arr1[:index1 + 1]
        del arr2[:index2 + 1]

        return tmp1



while a := get_max_element(arr1, arr2):
    ans.append(a)


print(len(ans))
print(*ans)