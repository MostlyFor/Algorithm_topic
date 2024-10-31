# 일단 펠린드롬이 가능한가? -> 홀수 몇 개?
name = input()

abcd = [0] * 26
for ch in name:
    abcd[ord(ch) - ord('A')]+=1

cnt = 0
one = ""
for i in range(len(abcd)):
    if abcd[i] % 2 == 1:
        cnt+=1
        one = chr(ord('A')+ i)
        abcd[i]-=1

if cnt > 1: 
    print("I'm Sorry Hansoo")
    quit()

ans = ""
# 사전 순으로 앞서는 펠린드롬 -> 그냥 알파벳 앞부터 출력
for i in range(len(abcd)):
    if abcd[i] > 0:
        cnt = abcd[i] // 2
        ans += chr(ord('A')+ i) * cnt

ans += one + ans[::-1]

print(ans)



