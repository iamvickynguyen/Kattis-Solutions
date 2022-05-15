from collections import deque
n, m = map(int, input().split())
adj = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

seen = [0 for i in range(n)]
q = deque([0])
seen[0] = 1
while q:
    u = q.popleft()
    for v in adj[u]:
        if seen[v] == 0:
            seen[v] = 1
            q.append(v)

flag = True
for i in range(n):
    if seen[i] == 0:
        print(i + 1)
        flag = False

if flag:
    print("Connected")
