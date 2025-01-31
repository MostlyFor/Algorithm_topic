from collections import deque

n = int(input())

queue = deque()

for _ in range(n):
    queue.append(_+1)

for _ in range(n-1):
    queue.popleft()
    tmp = queue.popleft()
    queue.append(tmp)

print(queue[0])

