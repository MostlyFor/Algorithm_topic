s = input()

ans = 0
i = 0
while i != len(s):
    if s[i:i+2] in ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']:
        i+=1
    if s[i:i+3] in ['dz=']:
        i+=2
    i+=1
    ans+=1
    
print(ans)