import sys
line = int(input())

# example: categories = {'query':['datastructure','graph'], 'sum':['datastructure']}
categories = {}
for x in range(line):
    data = input().split()
    name = data[0]
    for item in data[2:]:
        if item not in categories:
            categories[item] = [name]
        else:
            categories[item].append(name)

# count frequency
count = {}
for line in sys.stdin:
    line = line.strip()
    for w in line.split(" "):
        if w in categories:
            for item in categories[w]:
                if item not in count:
                    count[item] = 1
                else:
                    count[item] += 1

# take max frequency
l = []
# sorted_count = sorted(count.items(), key=lambda kv: kv[1], reverse=True)
# _max = sorted_count[0][1]
# for i in sorted_count:
#     if i[1] < _max:
#         break
#     l.append(i[0])
if len(count) > 0:
    _max = max(count.values())
    for key, val in count.items():
        if val == _max:
            l.append(key)

l.sort()
for x in l:
    print(x)
