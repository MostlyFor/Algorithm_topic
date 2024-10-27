data = list(map(int, input().split()))
list(map(lambda x: print(x[0] // x[1], x[0] % x[1]), [(data[i], data[i + 1]) for i in range(0, len(data), 2)]))
