import sys
input = sys.stdin.readline

n = int(input())

st = []
idx = 1

ans = []

for _ in range(n):
    target = int(input())

    # 만약에 스택에 있는 값이 작으면 target까지 append
    while len(st) == 0 or st[-1] < target:
        st.append(idx)
        idx+=1
        ans.append('+')
    
    top = st.pop()
    if top != target: print('NO'); quit()
    ans.append('-')

print(*ans, sep='\n')
    
    