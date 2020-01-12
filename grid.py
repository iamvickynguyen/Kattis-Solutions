import sys
from collections import deque

size = [int(x) for x in input().split()]
# read input
grid = []
for i in range(size[0]):
    row = [int(x) for x in list(input())]
    grid.append(row)

# init graph
graph = [[sys.maxsize for i in range(size[1])] for j in range(size[0])]
graph[0][0] = 0
q = deque()
q.append((0,0,0))

# update smaller jumps as we go
while q:
    item = q.popleft()
    r, c, w = item[0], item[1], item[2]
    j = grid[r][c]

    # up
    if r-j >= 0 and graph[r-j][c] > w + 1:
        graph[r-j][c] = w + 1
        q.append((r-j,c,w+1))

    # down
    if r+j < size[0] and graph[r+j][c] > w + 1:
        graph[r+j][c] = w + 1
        q.append((r+j,c,w+1))

    # left
    if c-j >= 0 and graph[r][c-j] > w + 1:
        graph[r][c-j] = w + 1
        q.append((r,c-j,w+1))

    # right
    if c+j < size[1] and graph[r][c+j] > w + 1:
        graph[r][c+j] = w + 1
        q.append((r,c+j,w+1))

val = graph[size[0]-1][size[1]-1]
print(val) if val < sys.maxsize else print(-1)