import sys
sys.setrecursionlimit(10**6)

arr = []

while True:
    try:
        arr.append(int(input()))
    except:
        break

left = [0] * (10 ** 6)
right = [0] * (10 ** 6)

st = []
st.append(arr[0])


# 트리 갱신
for i in range(1, len(arr)):
    st.append(arr[i])

    if arr[i-1] > arr[i]: # 왼쪽 자식
        left[arr[i-1]] = arr[i]
        
    elif arr[i-1] < arr[i]: # 오른쪽 자식

        while not st[-1] < arr[i] < st[-2]:
            st.pop()
            if len(st) == 1: break

        right[st[-1]] = arr[i]
        
        st.pop() # 오른쪽 자식을 채우는 순간 그 왼편은 평생 볼 일이 없음 -> 써먹은 st[-1] 빼주기
        st.append(arr[i]) # 자기 자신에 대한 정보 추가


def f(root): # 후위 출력 함수 왼쪽 -> 오른쪽 -> 루트
    if left[root]: f(left[root])
    if right[root]: f(right[root])
    print(root)

f(arr[0])