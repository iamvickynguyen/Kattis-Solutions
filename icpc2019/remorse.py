line = input().upper()

size = 0
dict = {}
for i in line:
    if i != ' ' and i != ',' and i != '.' and i != '!' and i != '?':
        try:
            dict[i] += 1
        except KeyError:
            dict[i] = 1
        size += 1

value = []
for val in dict.values():
    value.append(val)

value.sort(reverse = True)

count = 0
for i in range (len(value)):
    if i == 0:
        count += value[i]
    elif i < 3:
        count += 3*value[i]
    elif i < 6:
        count += 5*value[i]
    elif i < 11:
        count += 7*value[i]
    elif i < 19:
        count += 9*value[i]
    else:
        count += 11*value[i]

count += (size-1)*3

print(count)