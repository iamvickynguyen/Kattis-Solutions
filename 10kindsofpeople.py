from collections import deque

def flood_fill(graph, travel_map):
    visited = set()
    count = 0
    for r in range(len(graph)):
        for c in range(len(graph[0])):
            if (r, c) not in visited:
                q = deque()
                q.append((r,c))
                visited.add((r,c))
                number = graph[r][c]

                while q:
                    (y, x) = q.popleft()
                    travel_map[y][x] = count

                    # up
                    if (y-1 >= 0 and graph[y-1][x] == number and (y-1, x) not in visited):
                        q.append((y-1, x))
                        visited.add((y-1, x))

                    # down
                    if (y+1 < len(graph) and graph[y+1][x] == number and (y+1, x) not in visited):
                        q.append((y+1, x))
                        visited.add((y+1, x))

                    # left
                    if (x-1 >= 0 and graph[y][x-1] == number and (y, x-1) not in visited):
                        q.append((y, x-1))
                        visited.add((y, x-1))

                    # right
                    if (x+1 < len(graph[0]) and graph[y][x+1] == number and (y, x+1) not in visited):
                        q.append((y, x+1))
                        visited.add((y, x+1))

                count += 1

r, c = map(int, input().split())
graph= []
travel_map = [[-1 for i in range(c)] for j in range(r)]
for i in range(r):
    graph.append(input())
flood_fill(graph, travel_map)

n = int(input())
for i in range(n):
    r1, c1, r2, c2 = map(int, input().split())
    index = travel_map[r1-1][c1-1]
    index2 = travel_map[r2-1][c2-1]
    if index == index2:
        print('binary') if graph[r1-1][c1-1] == '0' else print('decimal')
    else:
        print('neither')