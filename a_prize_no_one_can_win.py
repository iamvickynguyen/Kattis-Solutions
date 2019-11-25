line = [int(x) for x in input().split()]
data = [int(x) for x in input().split()]
data.sort()

if line[0] == 1 or (line[0] > 1 and data[0] > line[1]):
    print(1)
else:
    items = 1
    boo = True
    for i in range(line[0]-1):
        if data[i] + data[i+1] > line[1]:
            items += i
            boo = False
            break

    if boo:
        items = line[0]
    print(items)
