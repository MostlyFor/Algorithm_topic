def solution(s):
    answer = []
    
    for s1 in s:
        st = []
        cnt = 0
        for ch in s1:
            st.append(ch)
            if st[-3:] == ['1', '1', '0']:
                cnt +=1
                for _ in range(3): st.pop()
        
        last_zero_idx = -1
        for i, v in enumerate(st):
            if v == '0':
                last_zero_idx = i
        
        answer.append("".join(st[:last_zero_idx+1]) + '110' * cnt + "".join(st[last_zero_idx+1:]))
                
        
    return answer