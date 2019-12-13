import sys
grid = [int(x) for x in input().split()]
row, col = grid[0], grid[1]
x, y = 0, 0
found = False
count = 0
gps = []
for _ in range(row):
    gps.append(input())

while(True):
    if x < 0 or x >= col or y < 0 or y >= row:
        print("Out")
        sys.exit(0)
    if gps[y][x] == 'T':
        print(count)
        sys.exit(0)
    if count > row*col*2:
        print("Lost")
        sys.exit(0)

    if gps[y][x] == 'N':
        y -= 1
    elif gps[y][x] == 'S':
        y += 1
    elif gps[y][x] == 'W':
        x -= 1
    elif gps[y][x] == 'E':
        x += 1
    count += 1
print("Lost")
