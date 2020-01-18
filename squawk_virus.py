from collections import deque

data = [int(x) for x in input().split()]
graph = [[] for i in range(data[0])]
for _ in range(data[1]):
    ip = input().split()
    graph[int(ip[0])].append(int(ip[1]))
    graph[int(ip[1])].append(int(ip[0]))

# add all neighbors of s to queue, and increment time t
q = deque()
count = 0
t = 0
user = {i: 0 for i in range(data[0])}
q.append([data[2], 0])
user[data[2]] = 1
while q and t < data[3]:
    v, t = q.popleft()
    for u in graph[v]:
        # if user[u] == 0:
        #     q.append([u, t+1])
        q.append([u, t+1])
        user[u] += user[v]
        if t + 1 == data[3]:
            count += user[v]
    user[v] = 0

print(count)
