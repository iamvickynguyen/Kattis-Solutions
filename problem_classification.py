import sys
line = int(input())

# example: categories = {'query':['datastructure','graph'], 'sum':['datastructure']}
classify_list = []  # name of all categories
categories = {}
for x in range(line):
    data = input().split()
    name = data[0]
    classify_list.append(name)
    for item in data[2:]:
        if item not in categories:
            categories[item] = [name]
        else:
            categories[item].append(name)

# init count
count = {}
for item in classify_list:
    count[item] = 0

# count frequency
for line in sys.stdin:
    line = line.rstrip()
    for w in line.split(" "):
        if w in categories:
            for item in categories[w]:
                count[item] += 1

# take max frequency
l = []
_max = max(count.values())
for key, val in count.items():
    if val == _max:
        l.append(key)

l.sort()
for x in l:
    print(x)
