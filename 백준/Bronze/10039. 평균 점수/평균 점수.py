sum = 0
for _ in range(5):
    score = int(input())
    sum += score if score >= 40 else 40
print(sum // 5)