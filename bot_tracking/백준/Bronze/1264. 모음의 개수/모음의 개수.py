while True:
    s = input()
    if s == '#': break
    cnt = 0
    for ch in s:
        if ch.lower() in ['a','e','i','o','u']:
            cnt+=1
    print(cnt)