import sys
for line in sys.stdin:
    a, op, b = map(str, line.split())
    if op == '^':
        print(int(str(pow(int(a), int(b), 10000))[-4:]))
    else:
        print(int(str(eval(line))[-4:]))
