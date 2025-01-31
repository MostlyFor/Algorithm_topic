str = input()

abcd = {}

for ch in str:
    if ch.upper() not in abcd:
        abcd[ch.upper()] = 1
    else:
        abcd[ch.upper()] += 1

sorted_abcd = sorted(abcd.items(), key = lambda item: item[1], reverse= 1)

if len(sorted_abcd) ==1:
    print(sorted_abcd[0][0])
    quit()

if sorted_abcd[0][1] == sorted_abcd[1][1]:
    print('?')
else:
    print(sorted_abcd[0][0])