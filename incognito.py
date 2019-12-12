cases = int(input())
for _ in range(cases):
    category = {}
    line = int(input())
    for i in range(line):
        data = input().split()
        if data[1] not in category:
            category[data[1]] = 1
        else:
            category[data[1]] += 1

    total = 1
    for val in category.values():
        total *= (val+1)
    print((total-1))