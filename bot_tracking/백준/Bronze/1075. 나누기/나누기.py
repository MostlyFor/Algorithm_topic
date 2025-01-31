a = int(input())
b = int(input())


a = int(a / 100) * 100

for i in range(0, 100):
    if (a + i) % b == 0:
        print(str(i+100)[1:])
        break