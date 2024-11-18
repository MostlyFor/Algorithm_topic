n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

def get_max_element(arr1, arr2, ans):
    if len(arr1) == 0 or len(arr2) == 0:
        return ans
    
    tmp1 = max(arr1)
    tmp2 = max(arr2)
    index1 = arr1.index(tmp1)
    index2 = arr2.index(tmp2)

    if tmp1 > tmp2:
        arr1.remove(tmp1)
        return get_max_element(arr1, arr2, ans)
    
    elif tmp1 < tmp2:
        arr2.remove(tmp2)
        return get_max_element(arr1, arr2, ans)
    
    else:
        ans.append(tmp1)
        return get_max_element(arr1[index1+1:], arr2[index2+1:], ans)

ans = get_max_element(arr1, arr2, [])

print(len(ans))
print(*ans)