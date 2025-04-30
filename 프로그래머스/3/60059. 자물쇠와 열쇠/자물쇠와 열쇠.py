def rotate(key, n, m):
    arr = [[0] * m for i in range(m)]
    
    for i in range(m):
        for j in range(m):
            arr[j][m-1-i] = key[i][j]
    
    return arr


def check(x, y, key, lock, n, m) -> bool:
    lock_tmp = [[0] * n for i in range(n)]
    
    # 복제
    for i in range(n):
        for j in range(n):
            lock_tmp[i][j] = lock[i][j]
            
    # key 옮기기
    for i in range(m):
        for j in range(m):
            if 0<=x+i<n and 0<=y+j<n:
                if key[i][j]^lock_tmp[x+i][y+j] == 0: return False
                lock_tmp[x+i][y+j] = 1
    
    # 합이 0 맞는지 확인하기
    # return sum(lock_tmp) == n * n
    return all(all(cell == 1 for cell in row) for row in lock_tmp)


def solution(key, lock):
    answer = False
    
    # key 시작 위치
    m = len(key)
    n = len(lock)
    
    for dir in range(0, 4):
        for x in range(-n, n):
            for y in range(-n, n):
                answer |= check(x, y, key, lock, n, m)
        key = rotate(key, n, m)
            
            
    return answer