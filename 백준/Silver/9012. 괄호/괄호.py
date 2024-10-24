T = int(input())

while T:
    T-=1
    str = input()
    st = []
    is_pos = True
    for ch in str:
        if ch == '(':
            st.append(ch)
        elif ch == ')':
            if len(st) == 0 or st[-1] != '(':
                is_pos=False
                break
            else:
                st.pop()

    if is_pos and not st:
        print("YES")
    else:
        print("NO")

    