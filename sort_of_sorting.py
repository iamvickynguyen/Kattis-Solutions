import functools


def cmp_key(x, y):
    if x[0] == y[0]:
        if x[1] == y[1]:
            return 0
        else:
            return 1 if x[1] > y[1] else -1
    else:
        return 1 if x[0] > y[0] else -1


line = int(input())
while line != 0:
    names = []
    for _ in range(line):
        names.append(input())

    sorted_name = sorted(names, key=functools.cmp_to_key(cmp_key))

    for i in sorted_name:
        print(i)
    print()
    line = int(input())
