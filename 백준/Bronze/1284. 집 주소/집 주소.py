while True:
    arr = input()
    if arr == "0": break
    ans = 2 + len(arr) - 1
    for ch in arr:
        if ch == '0': ans += 4
        elif ch == '1': ans +=2
        else: ans +=3
    print(ans)