s = input()
dict1 = "0123456789ABCDEF"
ans = 0
i = 0
for ch in s:
    idx = dict1.index(ch)
    ans += idx * (16 ** (len(s) - i - 1))
    i+=1
    
print(ans)
    
