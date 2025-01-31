import sys
import math

input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    M, N, x, y = map(int,input().rstrip().split())

    # M * k1 + x = N * k2 + y 를 만족하는 정수 (k1, k2) 찾기

    limit = M * N // math.gcd(M, N) // M

    found = False

    for i in range(0, limit+1):
        k2 = (M * i + x - y) / N

        if (M * i + x - y) % N == 0:
            print((M * i + x - y) // N  * N + y)
            found= True
            break
    
    if not found:
        print(-1)
