line = int(input())
time = []
dist = []
for i in range (line):
    data = input().split(" ")
    time.append(int(data[0]))
    dist.append(int(data[1]))

_max = -1
for i in range (line):
    for j in range (i+1, line):
        speed = (dist[j]-dist[i])/(time[j]-time[i])
        if speed > _max:
            _max = speed

print(int(_max))