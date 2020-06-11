from collections import deque
w, h = map(int, input().split())
graph = []
for _ in range(h):
    graph.append(input())

q = deque()
visited = set()
for r in range(h):
    for c in range(w):
        if graph[r][c] == 'P':
            q.append((r,c))
            visited.add((r,c))
            break
    else:
        continue
    break

count = 0
while q:
    (r,c) = q.popleft()
    if graph[r][c] == 'G':
        count += 1

    # add neighbours
    if (((r-1 >= 0 and graph[r-1][c] != 'T') or r-1 < 0) and
        ((r+1 < h and graph[r+1][c] != 'T') or r+1 >= h) and
        ((c-1 >= 0 and graph[r][c-1] != 'T') or c-1 < 0) and
        ((c+1 < w and graph[r][c+1] != 'T') or c+1 >= w)):
        if r - 1 >= 0 and (r-1, c) not in visited and graph[r-1][c] != '#' and graph[r-1][c] != 'T':
            q.append((r-1, c))
            visited.add((r-1, c))
        if r + 1 < h and (r+1, c) not in visited and graph[r+1][c] != '#' and graph[r+1][c] != 'T':
            q.append((r+1, c))
            visited.add((r+1, c))
        if c - 1 >= 0 and (r, c-1) not in visited and graph[r][c-1] != '#' and graph[r][c-1] != 'T':
            q.append((r, c-1))
            visited.add((r, c-1))
        if c + 1 < w and (r, c+1) not in visited and graph[r][c+1] != '#' and graph[r][c+1] != 'T':
            q.append((r, c+1))
            visited.add((r, c+1))

print(count)