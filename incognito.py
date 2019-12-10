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

    values = list(category.values())

    total = line
    for i in range(len(values)):
        table = [0]
        for j in range(i+1, len(values)):
            two_sets = values[i] * values[j]
            total += two_sets
            size = len(table)
            for item in range(1, size):
                x = values[j] * table[item]
                total += x
                table.append(x)
            table.append(two_sets)

    print(total)
