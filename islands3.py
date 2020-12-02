from collections import deque

def bfs(image, visited, y, x):
    q = deque()
    q.append((x,y))
    visited[y][x] = True
    while q:  
        (x,y) = q.popleft()
        # up
        if y - 1 >= 0 and not visited[y - 1][x] and image[y - 1][x] in ['L', 'C']:
            q.append((x, y-1))
            visited[y-1][x] = True

        # down
        if y + 1 < len(image) and not visited[y + 1][x] and image[y + 1][x] in ['L', 'C']:
            q.append((x, y+1))
            visited[y+1][x] = True

        # left
        if x - 1 >= 0 and not visited[y][x - 1] and image[y][x - 1] in ['L', 'C']:
            q.append((x-1, y))
            visited[y][x-1] = True

        # right
        if x + 1 < len(image[0]) and not visited[y][x + 1] and image[y][x + 1] in ['L', 'C']:
            q.append((x+1, y))
            visited[y][x+1] = True

r,c = map(int, input().split())
image = []
lands = set()
for y in range(r):
    line = input()
    image.append(line)
    for x in range(c):
        if line[x] == 'L':
            lands.add((x,y))

if len(lands) == 0:
    print(0)
else:
    visited = [[False for i in range(c)] for j in range(r)]
    count = 0
    for (x, y) in lands:
        if not visited[y][x]:
            bfs(image, visited, y, x)
            count += 1
    print(count)