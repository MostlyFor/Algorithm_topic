while True:
    s = input()
    if s == '.': break

    is_balanced = True

    st = []

    for ch in s:
        if ch == '(' or ch == '[':
            st.append(ch)
        
        elif ch == ')':
            if len(st) == 0 or st[-1] != '(':
                is_balanced = False

                break
            st.pop()
            
        elif ch == ']':
            if len(st) == 0 or st[-1] != '[':
                is_balanced = False
                break
            st.pop()

    if is_balanced and len(st) == 0:
        print('yes')
    else: print('no')