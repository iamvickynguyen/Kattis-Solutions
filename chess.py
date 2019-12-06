# idea: find intersections of 2 lines

# positions that bishop can go in 1 move


def one_move(x, y):
    moves = set()
    for i in range(1, 9):
        for j in range(1, 9):
            if abs(i-x) == abs(j-y):
                point = (i, j)
                moves.add(point)
    return moves


line = int(input())
dict = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8}
dict_reverse = {val: key for key, val in dict.items()}
for i in range(line):
    data = input().split()
    source = (dict[data[0]], int(data[1]))
    destination = (dict[data[2]], int(data[3]))

    # if only takes 0 move
    if source == destination:
        print(str(0) + " " + data[0] + " " + data[1])

    else:
        set1 = one_move(source[0], source[1])

        # if only takes 1 move, then output
        if destination in set1:
            print(str(1) + " " + data[0] + " " +
                  data[1] + " " + data[2] + " " + data[3])

        else:
            # if takes more than 1 move
            set2 = one_move(destination[0], destination[1])

            intersect = set1.intersection(set2)
            if len(intersect) == 0:
                print("Impossible")
            else:
                move = intersect.pop()
                print(str(2) + " " + data[0] + " " + data[1] + " " +
                      dict_reverse[move[0]] + " " + str(move[1]) + " " + data[2] + " " + data[3])
