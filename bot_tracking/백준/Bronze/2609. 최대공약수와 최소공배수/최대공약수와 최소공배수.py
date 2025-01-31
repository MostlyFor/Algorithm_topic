a,b = map(int, input().split())
if a < b:
    a,b = b,a
    
mul = a * b

while b:
    r = a % b
    a = b
    b = r
    
print(a)
print(int(mul / a))