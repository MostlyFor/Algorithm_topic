import sys

input = sys.stdin.readline

n, m = map(int ,input().split())

dict1 = {}
dict2 = {}

for i in range(1,n+1):
    s = input().rstrip()
    dict1[i] = s
    dict2[s] = i

for i in range(m):
    s = input().rstrip()
    if ord(s[0]) <= ord('Z') and ord('A') <= ord(s[0]):
        print(dict2[s])
    else:
        print(dict1[int(s)])