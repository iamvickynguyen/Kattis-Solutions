data = [int(x) for x in input().split()]
graph = [[] for i in range(data[0])]
for _ in range(data[1]):
    ip = input().split()
    graph[int(ip[0])].append(int(ip[1]))
    graph[int(ip[1])].append(int(ip[0]))

# use 2 dictionaries
# add all neighbours to the other dictionary, clear the current
# switch dictionary as we go
# if meet a repeated key, increment the value
t = data[3]
d1 = {}
d2 = {}
d1[data[2]] = 1
while t > 0:
    if len(d1) > 0:
        for k, v in d1.items():
            for u in graph[k]:
                if u in d2:
                    d2[u] += v
                else:
                    d2[u] = v
        d1.clear()
    else:
        for k, v in d2.items():
            for u in graph[k]:
                if u in d1:
                    d1[u] += v
                else:
                    d1[u] = v
        d2.clear()
    t -= 1

if len(d1) > 0:
    print(sum(d1.values()))
elif len(d2) > 0:
    print(sum(d2.values()))
else:
    print(0)
