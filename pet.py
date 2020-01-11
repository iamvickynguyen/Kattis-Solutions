_max, index = 0, 0
for i in range(5):
    total = sum([int(x) for x in input().split()])
    if total > _max:
        _max = total
        index = i

print(str(index+1) + ' ' + str(_max))
