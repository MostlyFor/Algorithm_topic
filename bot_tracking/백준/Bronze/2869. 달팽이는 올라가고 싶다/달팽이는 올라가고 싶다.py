a, b, v = map(int, input().split())

dt = a-b

print((v-a) // dt + ((v-a) % dt > 0) + 1)