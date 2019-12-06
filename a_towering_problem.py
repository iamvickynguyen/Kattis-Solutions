import sys


def check_other_boxes(data, i, j, k, tower2):
    # height of tower 2
    boxes2 = []
    height2 = 0
    for x in range(6):
        if x != i and x != j and x != k:
            boxes2.append(data[x])
            height2 += data[x]

    if height2 == tower2:
        return True, boxes2
    return False, None


data = [int(x) for x in input().split()]


for i in range(6):
    for j in range(i+1, 6):
        for k in range(j+1, 6):
            if data[i] + data[j] + data[k] == data[6]:
                val = check_other_boxes(data, i, j, k, data[7])
                if val[0]:
                    tower1 = [data[i], data[j], data[k]]
                    tower1.sort(reverse=True)
                    tower2 = val[1]
                    tower2.sort(reverse=True)
                    tower1 += tower2
                    for item in tower1:
                        print(item, end=' ')
                    sys.exit(0)
