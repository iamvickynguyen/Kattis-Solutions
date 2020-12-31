s = input()
c = {}
for i in s:
    if i in c:
        c[i] += 1
    else:
        c[i] = 1
oddcount = sum(map(lambda x: x % 2, list(filter(lambda x: x % 2 != 0, c.values()))))
print(max(0, oddcount - 1))