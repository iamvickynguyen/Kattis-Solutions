def laser(direction, board, x, y):
    if direction == 0:
        if x + 1 >= 8 or board[y][x + 1] != 'I':
            return True
        else:
            board[y][x + 1] = '.'
    elif direction == 2:
        if x - 1 < 0 or board[y][x - 1] != 'I':
            return True
        else:
            board[y][x - 1] = '.'
    elif direction == 1:
        if y + 1 >= 8 or board[y + 1][x] != 'I':
            return True
        else:
            board[y + 1][x] = '.'
    else:
        if y - 1 < 0 or board[y - 1][x] != 'I':
            return True
        else:
            board[y - 1][x] = '.'
    return False

def move(direction, board, x, y):
    if direction == 0:
        if x + 1 >= 8 or board[y][x + 1] in ['C', 'I']:
            return x, y, True
        return x + 1, y, False
    elif direction == 2:
        if x - 1 < 0 or board[y][x - 1] in ['C', 'I']:
            return x, y, True
        return x - 1, y, False
    elif direction == 1:
        if y + 1 >= 8 or board[y + 1][x] in ['C', 'I']:
            return x, y, True
        return x, y + 1, False
    else:
        if y - 1 < 0 or board[y - 1][x] in ['C', 'I']:
            return x, y, True
        return x, y - 1, False

board = [[char for char in input()] for i in range(8)]
direction = 0 # 0: east, 1: south, 2: west, 3: north
x, y = 0, 7
bug = False
ins = input()
for i in range(len(ins)):
    if ins[i] == 'L':
        direction = (direction + 4 - 1) % 4
    elif ins[i] == 'R':
        direction = (direction + 1) % 4
    elif ins[i] == 'X':
        bug = laser(direction, board, x, y)
        if bug:
            break
    else:
        x, y, bug = move(direction, board, x, y)
        if bug:
            break

if bug or board[y][x] != 'D':
    print('Bug!')
else:
    print('Diamond!')