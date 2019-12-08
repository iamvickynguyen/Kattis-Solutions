# recursively divide big map into 4 parts
def find_coordinate(num, start_col, start_row):
    global dict
    if len(num) == 1:
        return [dict[num[0]][0] + start_col, dict[num[0]][1] + start_row]
    n = 2**len(num)
    coordinate = dict[num[0]]
    start_col = coordinate[0] * n//2 + start_col
    start_row = coordinate[1] * n//2 + start_row
    return find_coordinate(num[1:], start_col, start_row)


dict = {'0': [0, 0], '1': [1, 0], '2': [0, 1], '3': [1, 1]}
num = [x for x in input()]
coordinate = find_coordinate(num, 0, 0)
print(str(len(num)) + " " + str(coordinate[0]) + " " + str(coordinate[1]))
