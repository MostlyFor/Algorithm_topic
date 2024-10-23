string = input()
arr = [-1] * 26

for i in range(len(string)):
    ch = string[i]
    index = ord(ch) - ord('a')
    if arr[index] == -1:
        arr[index] = i

print(*arr, sep=' ')
