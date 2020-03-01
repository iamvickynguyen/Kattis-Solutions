import sys
names = []
first = set()
same_first_name = set()
for line in sys.stdin:
    line = line.strip().split()
    names.append(line)

    if line[0] in first:
        same_first_name.add(line[0])
    first.add(line[0])

names = sorted(names, key = lambda x: [x[1], x[0]])
for first, last in names:
    if first in same_first_name:
        print(first + ' ' + last)
    else:
        print(first)