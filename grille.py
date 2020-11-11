import math
import sys

n = int(input())
grid = []
grilles = 0
for i in range(n):
    s = input()
    grid.append(s)
    grilles += s.count('.')

s = input()

if grilles == 0 or n*n //4 != grilles:
    print("invalid grille")
    sys.exit(0)

msg = [[None for j in range(n)] for i in range(n)]
index = 0
for i in range(4):
    for r in range(n):
        for c in range(n):
            if grid[r][c] == '.':
                msg[r][c] = s[index]
                index += 1

    grid = list(zip(*grid[::-1]))

out = ''
for r in range(n):
    for c in range(n):
        if msg[r][c] == None:
            print("invalid grille")
            sys.exit(0)
        out += msg[r][c]
print(out)