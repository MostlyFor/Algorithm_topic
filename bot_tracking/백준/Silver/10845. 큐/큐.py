import sys
input = sys.stdin.readline

queue = []

idx = 0

n = int(input().rstrip())

for _ in range(n):
    tmp = input().rstrip().split()

    if len(tmp) == 2:
        queue.append(tmp[1])
    
    elif tmp[0] == 'front':
        if len(queue) == idx: print(-1)
        else: print(queue[idx])
    elif tmp[0] == 'back':
        if len(queue) == idx: print(-1)
        else: print(queue[-1])
    elif tmp[0] == 'empty':
        print(int(len(queue) == idx))
    elif tmp[0] == 'size':
        print(len(queue) - idx)
    elif tmp[0] == 'pop':
        if len(queue) == idx:
            print(-1)
        else:
            print(queue[idx])
            idx+=1