def merge(row):
    for i in range(3):
        if row[i] == row[i + 1]:
            row[i] *= 2
            row[i + 1] = 0
            row = list(filter(lambda x: x != 0, row))
            row.extend([0] * (4 - len(row)))
    return row

grid = [[int(i) for i in input().split()] for j in range(4)]
move = int(input())
if move == 0:
    for j in range(4):
        newrow = list(filter(lambda x: x != 0, grid[j]))
        newrow.extend([0] * (4 - len(newrow)))
        newrow = merge(newrow)
        grid[j] = newrow
    for i in range(4):
        for j in range(4):
            print(grid[i][j], end=" ")
        print()
elif move == 2:
    for j in range(4):
        newrow = list(filter(lambda x: x != 0, grid[j]))
        newrow.reverse()
        newrow.extend([0] * (4 - len(newrow)))
        newrow = merge(newrow)
        newrow.reverse()
        grid[j] = newrow
    for i in range(4):
        for j in range(4):
            print(grid[i][j], end=" ")
        print()
elif move == 1:
    output = []
    for j in range(4):
        newrow = [r[j] for r in grid]
        newrow = list(filter(lambda x: x != 0, newrow))
        newrow.extend([0] * (4 - len(newrow)))
        newrow = merge(newrow)
        output.append(newrow)
    for i in range(4):
        for j in range(4):
            print(output[j][i], end=" ")
        print()
else:
    output = []
    for j in range(4):
        newrow = [r[j] for r in grid]
        newrow = list(filter(lambda x: x != 0, newrow))
        newrow.reverse()
        newrow.extend([0] * (4 - len(newrow)))
        newrow = merge(newrow)
        newrow.reverse()
        output.append(newrow)
    for i in range(4):
        for j in range(4):
            print(output[j][i], end=" ")
        print()