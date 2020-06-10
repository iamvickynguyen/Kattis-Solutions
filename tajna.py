import math
s = input()
row = int(math.sqrt(len(s)))
while len(s) % row != 0:
    row -= 1
col = len(s) // row

matrix = []
for i in range(col):
    a_row = s[row*i : row+row*i]
    matrix.append(a_row)

result = ''
for j in range(row):
    for i in range(col):
        result += matrix[i][j]

print(result)