line = int(input())
for i in range(line):
    x = input().split()
    s = x[0] + ' '
    try:
        s += str(int(x[1], 8)) + " "
    except ValueError:
        s += '0 '
    try:
        s += str(int(x[1], 10)) + " "
    except ValueError:
        s += '0 '
    try:
        s += str(int(x[1], 16)) + " "
    except ValueError:
        s += '0 '
    print(s)
