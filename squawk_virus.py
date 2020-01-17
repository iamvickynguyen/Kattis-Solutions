from collections import deque

data = [int(x) for x in input().split()]
graph = [[] for i in range(data[0])]
for _ in range(data[1]):
    ip = input().split()
    graph[int(ip[0])].append(int(ip[1]))
    graph[int(ip[1])].append(int(ip[0]))

# add all neighbors of s to queue, and increment time t
time = 0
# q = deque()
index = 0
q = []
q.append((data[2], 0))
# while time < data[3] and q:
while time < data[3] and index < len(q):
    # s, time = q.popleft()
    time = q[index][1]
    s = q[index][0]
    for neighbor in graph[s]:
        q.append((neighbor, time + 1))
    index += 1

# if nothing in the queue, print(1)
# else, count the number of items that have time == t
count = len([x for x in range(len(q)) if q[x][1] == data[3]])
print(0) if not q else print(count)
