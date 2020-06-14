from collections import deque
n = int(input())
for _ in range(n):
    m = int(input())
    r = int(input())
    if r < 1:
        print(m-1)
    else:
        graph = {}
        for i in range(r):
            u, v = map(int, input().split())
            if u not in graph:
                graph[u] = [v]
            else:
                graph[u].append(v)

            if v not in graph:
                graph[v] = [u]
            else:
                graph[v].append(u)

        q = deque()
        visited = set()
        count = 0
        for road in range(m):
            if road not in visited:
                q.append(road)
                visited.add(road)
                count += 1
                while q:
                    v = q.popleft()
                    if v in graph:
                        for u in graph[v]:
                            if u not in visited:
                                q.append(u)
                                visited.add(u)
        print(count-1)