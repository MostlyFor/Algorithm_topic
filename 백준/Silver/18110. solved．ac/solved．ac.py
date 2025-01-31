import sys
input = sys.stdin.readline

n = int(input())
if n == 0: print(0) ; quit()
arr = []
for i in range(n):
    arr.append(int(input()))

arr.sort()

drop_n = n * 15 // 100 + ( (n * 15) % 100 >= 50 )

score = sum(arr[drop_n : n-drop_n])

n -= drop_n * 2

print(score // n + (score % n >= n/2))