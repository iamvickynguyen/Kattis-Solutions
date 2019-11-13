import sys

n = int(input())
matrix = []
for x in range (n):
    line = list(input())
    matrix.append(line)

boo = True

b = 0
w = 0
for i in range (n):
    for j in range (i+1, n):
        if matrix[i][j] == 'B':
            b += 1
            w = 0
            if b > 2:
                print(0)
                boo = False
                sys.exit(0)
        if matrix[i][j] == 'W':
            w += 1
            b = 0
            if w > 2:
                print(0)
                boo = False
                sys.exit(0)
for i in range (n):
    b = 0
    w = 0
    for j in range (i, n):
        if matrix[j][i] == 'B':
            b += 1
            w = 0
            if b > 2:
                print(0)
                boo = False
                sys.exit(0)
               
        if matrix[j][i] == 'W':
            w += 1
            b = 0
            if w > 2:
                print(0)
                boo = False
                sys.exit(0)

if boo:
    print(1)


