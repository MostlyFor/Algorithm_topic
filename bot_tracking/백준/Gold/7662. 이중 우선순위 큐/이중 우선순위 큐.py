import sys
import heapq

input = sys.stdin.readline



T = int(input().rstrip())
for _ in range(T):
    heap_min = []
    heap_max = []

    state = {}

    n = int(input().rstrip())
    for _ in range(n):
        cmd, x = input().rstrip().split()
        x = int(x)

        if cmd == 'I':
            heapq.heappush(heap_min, x)
            heapq.heappush(heap_max, -x)
            state[x] = state.get(x, 0) + 1
        
        elif cmd == 'D':
            if len(state) and x == -1:
                x = heapq.heappop(heap_min)
                while state.get(x, 0) == 0:
                    x = heapq.heappop(heap_min)
                state[x] = state.get(x, 0) - 1

            
            elif len(state) and x == 1:
                x = -heapq.heappop(heap_max)
                while state.get(x, 0) == 0:
                    x = -heapq.heappop(heap_max)
                state[x] = state.get(x, 0) - 1


            if len(state) and state[x] == 0:
                del state[x]
    

    if len(state) == 0:
        print('EMPTY')

    else:
        print(max(state.keys()), min(state.keys()), sep = ' ')