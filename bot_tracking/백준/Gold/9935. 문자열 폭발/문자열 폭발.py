import sys
from collections import deque
input = sys.stdin.readline

s = input().rstrip()
target = input().rstrip()

stack = []
for ch in s:
    stack.append(ch)

    if len(stack) < len(target): continue
    tmp = "".join(stack[-len(target):])
    if tmp == target:
        for _ in range(len(target)):
            stack.pop()

ans = "".join(stack)
if ans:
    print(ans)
else:
    print('FRULA')