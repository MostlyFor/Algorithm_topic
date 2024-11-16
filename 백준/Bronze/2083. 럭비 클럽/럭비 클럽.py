while True:
    name, age, w = input().split()
    age, w = map(int, [age, w])

    if name == '#':
        break
    if age > 17 or w >= 80:
        print(name, 'Senior', sep=' ')
    else:
        print(name, 'Junior', sep=' ')